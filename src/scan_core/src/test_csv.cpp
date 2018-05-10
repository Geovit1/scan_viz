#include "data_rider/csv/Testdata.h"
#include "data_rider/csv/Sbgdata.h"
#include "data_rider/dir_brouser/DirBrouser.h"
#include <iostream>


using namespace drider::csv;
using namespace drider;
using namespace std;

int main(int argc, char *arv[]) 
{
    Sbgdata<SbgLine> *tmp = new Sbgdata<SbgLine>();
    tmp->Open(DirBrouser::DataDirectory("sbg.csv"));
    int flag;
    SbgLine some;
    while((flag = tmp->ReadCsvRaw(some)) == Sbgdata<SbgLine>::Status::OPENED)
    cout << some.ros_timestamp << " " << 
            (int)some.year << " " <<
            (int)some.month << " " <<
            (int)some.day << " " <<
            (int)some.hour << " " <<
            (int)some.minute << " " <<
            (int)some.second << " " <<
            some.utc_nanosecond << " " <<
            some.gps_week << " " <<
            some.clock_stable << " " <<
            some.clock_status << " " <<
            some.clock_utc_sync << " " <<
            some.clock_utc_status << " " <<
            some.roll << " " <<
            some.pitch << " " <<
            some.yaw << " " <<
            some.north << " " <<
            some.east << " " <<
            some.down << " " <<
            some.latitude << " " <<
            some.longitude << " " <<
            some.attitude << " " <<
            some.undulation << " " <<
            (int)some.solution_mode << endl;


}

/*int main(int argc, char *argv[])
{
    Testdata<TestDataLine> *tmp = new Testdata<TestDataLine>();
    bool wtf=tmp->Create("/home/zf/scan_viz/src/scan_core/scan_core_files/data/test.csv");
    std::cout<<wtf<<std::endl;
    TestDataLine some;
    some.timestamp = 91191;
    some.flag = 6;
    some.x = 1.00000;
    some.y = 2.00000;
    some.z = 3.00000;

    tmp->WriteCsvRaw(some);
    some.flag = 7;
    tmp->WriteCsvRaw(some);
    some.flag = 8;
    tmp->WriteCsvRaw(some);
    tmp->Close();
    tmp->Open("/home/zf/scan_viz/src/scan_core/scan_core_files/data/test.csv");
    TestDataLine some1;
    for (int i = 0; i < 5; i++) {
        int flag;
        while((flag = tmp->ReadCsvRaw(some1)) == Testdata<TestDataLine>::Status::OPENED)
        cout << some1.timestamp << " " << (int)some1.flag << endl;
        if (flag == Testdata<TestDataLine>::Status::EOFILE) {
            tmp->Reopen();
        }
    }
    
    return 0;
}*/
