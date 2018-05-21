#include "scan_core/godeye_retina/Pathway.h"

namespace godeye_retina
{
    Pathway::Pathway(std::string frameid)
    {
        m_pathway.header.frame_id = frameid;
    }

    
}