#include "SistemaEstanques_PID_discreto_capi_host.h"
static SistemaEstanques_PID_discreto_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        SistemaEstanques_PID_discreto_host_InitializeDataMapInfo(&(root), "SistemaEstanques_PID_discreto");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
