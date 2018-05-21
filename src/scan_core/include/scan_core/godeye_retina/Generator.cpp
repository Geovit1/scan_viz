#include "scan_core/godeye_retina/Generator.h"

namespace godeye_retina
{
    GeneratorFinalData::GeneratorFinalData(std::string filepath)
    {
        m_csvdata.Open(filepath);

        FinalDataLine raw; 
        m_csvdata.ReadCsvRaw(raw);
        m_start_offset_xyz = mathmodel::GeographicToGeocentric(raw.latitude, raw.longitude, raw.attitude);
        
        m_csvdata.Reopen();
    }

    void GeneratorFinalData::NextData(pcl::PointCloud<pcl::PointXYZI> &cloud,
                                        ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy)
    {
        std::vector<FinalDataLine> list;

        int  status = m_csvdata.ReadCsvPart(m_bundle_size, list);
        std::cout<< status<< " " << list.size() << std::endl;
        if( list.size()> 0 )
        {
            pos_xyz =(mathmodel::GeographicToGeocentric(list[0].latitude, list[0].longitude, list[0].attitude) - m_start_offset_xyz)/100;
            rpy[0] = list[0].roll;
            rpy[1] = list[0].pitch;
            rpy[2] = list[0].yaw;

            cloud.resize(list.size());
            for(int i=0; i<list.size(); i++)
            {   
                cloud.points[ i ].x = list[i].x/10;
                cloud.points[ i ].y = list[i].y/10;
                cloud.points[ i ].z = list[i].z/10;
                cloud.points[ i ].intensity = ( int ) (list[i].intensity);
            }
        }

        if( status == Finaldata<FinalDataLine>::Status::EOFILE)
            m_csvdata.Reopen();

    }

    void GeneratorFinalData::OnStartPosition()
    {
        m_csvdata.Reopen();
    }

    void GeneratorFinalData::SetBundleSize(unsigned int bundle_size)
    {
        m_bundle_size = bundle_size;
    }
    
}
