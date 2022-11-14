#ifndef RTW_HEADER_SistemaEstanques_PID_discreto_h_
#define RTW_HEADER_SistemaEstanques_PID_discreto_h_
#ifndef SistemaEstanques_PID_discreto_COMMON_INCLUDES_
#define SistemaEstanques_PID_discreto_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "SistemaEstanques_PID_discreto_types.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rt_nonfinite.h"
#define MODEL_NAME SistemaEstanques_PID_discreto
#define NSAMPLE_TIMES (6) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (25) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T m2w3hx33rl ; real_T ga0bmsoaao ; real_T kqhghyeq3z ;
real_T pbcmo2oung ; real_T hlxlc4tizq ; real_T pamg2ltvgy ; real_T lku50azrkb
; real_T ggov1pk5jg ; real_T otvgwe1e1e ; real_T eicjvshfeq ; real_T
bnnrwyns0c ; real_T kv0eqywsiz ; real_T mjd1ansmc2 ; real_T m4eclbfi40 ;
real_T c2nnsvritk ; real_T amqerpar2b ; real_T hz5ifhc25c ; real_T ns50kkurdv
; real_T evoblqrjee ; real_T hlqeedqmkd ; real_T nwa0blftqa ; real_T
hqhvmmqb2r ; real_T cawe1pel2l ; real_T p2gs34a42l ; real_T acnxapdnky ; } B
; typedef struct { real_T f1gmat2bv1 ; real_T dwaftwnef5 ; struct { void *
LoggedData ; } aexhwn1xad ; struct { void * LoggedData ; } bdn1melcib ;
struct { void * LoggedData ; } laev3pmnli ; struct { void * AQHandles ; }
n2alg3gtxb ; struct { void * AQHandles ; } pkvrcopyel ; struct { void *
AQHandles ; } ny23d4etja ; struct { void * AQHandles ; } f2mr0nuv1k ; struct
{ void * LoggedData ; } cmjlyn03fb ; struct { void * AQHandles ; }
n2alg3gtxbm ; struct { void * AQHandles ; } avu4vt3ihx ; struct { void *
AQHandles ; } pkvrcopyelh ; struct { void * AQHandles ; } ny23d4etjaa ;
struct { void * AQHandles ; } avu4vt3ihx4 ; struct { void * LoggedData ; }
jkuvpd2pz1 ; struct { void * AQHandles ; } n52vpgrthw ; uint32_T hxixz0diaj ;
uint32_T phkyglsksj ; uint32_T fkpuglvoce ; uint32_T mxczgh10dw ; uint32_T
nhjl40zo3t ; uint32_T pvkjz3veq1 ; uint32_T mfqkf0zqeo ; uint32_T ksfiloike2
; uint32_T l2kheao0b5 ; uint32_T kbdgvwackz ; uint32_T lbxi5wwnx3 ; uint32_T
hc55zqdtz0 ; uint32_T mqicor4wcz ; uint32_T h0wbwp43sy ; uint32_T n3yhdhd3sz
; uint32_T bbtqzyjvdv ; uint32_T nr0mtfjxwf ; uint32_T dzabhw2v3z ; boolean_T
cijhhdchyo ; boolean_T ik50j3b4la ; boolean_T ercrtsl3ul ; boolean_T
ajg1qa13qd ; boolean_T no0onatjsa ; boolean_T f1vped4bnl ; boolean_T
o0b14vit54 ; boolean_T ltv1e4zdnf ; boolean_T cbpmfl3daa ; boolean_T
ihzo0v2eqx ; boolean_T opu3gm1und ; boolean_T loyc4qmd00 ; boolean_T
dlka5jhs0h ; boolean_T ccq1r4uodm ; boolean_T eeyqmg1sps ; boolean_T
aiqbe2qv5w ; boolean_T arn25zbrew ; boolean_T k4odt4vyi3 ; } DW ; typedef
struct { real_T n5jaiqo4q1 ; real_T oijbjoorjx ; real_T kq0qmjau05 ; } X ;
typedef struct { real_T n5jaiqo4q1 ; real_T oijbjoorjx ; real_T kq0qmjau05 ;
} XDot ; typedef struct { boolean_T n5jaiqo4q1 ; boolean_T oijbjoorjx ;
boolean_T kq0qmjau05 ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi
; } DataMapInfo ; struct P_ { real_T PIDController_D ; real_T
SistemadeEstanques_Fout_null ; real_T PIDController_I ; real_T
PIDController_InitialConditionForFilter ; real_T
PIDController_InitialConditionForIntegrator ; real_T Ramp1_InitialOutput ;
real_T Ramp2_InitialOutput ; real_T PIDController_LowerSaturationLimit ;
real_T PIDController_N ; real_T PIDController_P ; real_T
WaveformGenerator_SelectedSignal ; real_T
WaveformGenerator_SelectedSignal_f3od4jcqqc ; real_T ruido_SelectedSignal ;
real_T ruido1_SelectedSignal ; real_T SistemadeEstanques_T0c ; real_T
SistemadeEstanques_T0r ; real_T PIDController_UpperSaturationLimit ; real_T
SistemadeEstanques_h0 ; real_T Ramp1_slope ; real_T Ramp2_slope ; real_T
Ramp1_start ; real_T Ramp2_start ; real_T Integrador_UpperSat ; real_T
Integrador_LowerSat ; real_T beta_Gain ; real_T Step_Y0 ; real_T
Saturation1_UpperSat ; real_T Saturation1_LowerSat ; real_T
Step_Y0_h2h1sloxcm ; real_T Saturation2_UpperSat ; real_T
Saturation2_LowerSat ; real_T Saturador2_UpperSat ; real_T
Saturador2_LowerSat ; real_T uK1_Gain ; real_T uK2_Gain ; real_T Gain_Gain ;
real_T Gain1_Gain ; real_T Gain2_Gain ; real_T Gain_Gain_okzxc23qf2 ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T Integrator_gainval
; real_T Filter_gainval ; real_T Saturador1_UpperSat ; real_T
Saturador1_LowerSat ; real_T C1_Gain ; real_T Constant_Value ; real_T
Constant1_Value ; real_T C2_Value ; real_T Constant_Value_nh4qnxlmtb ; real_T
Constant1_Value_pxdhqqllht ; real_T K3_Value ; real_T constant_Value ; real_T
constant1_Value ; real_T cp_Value ; real_T cp1_Value ; real_T ha_Value ;
real_T km_Value ; real_T rho_Value ; real_T rho1_Value ; real_T M_Value ;
real_T constant_Value_dbb4dojqmp ; real_T cp_Value_eh2zrr2jtp ; real_T
cp1_Value_hzyk4t5t4c ; real_T ha_Value_llewwjyayt ; real_T
km_Value_feeasfdogm ; real_T km1_Value ; real_T rho_Value_k2fdqeovty ; real_T
rho1_Value_oipnu5fd53 ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern mxArray
* mr_SistemaEstanques_PID_discreto_GetDWork ( ) ; extern void
mr_SistemaEstanques_PID_discreto_SetDWork ( const mxArray * ssDW ) ; extern
mxArray * mr_SistemaEstanques_PID_discreto_GetSimStateDisallowedBlocks ( ) ;
extern void MdlUpdateTID2 ( int_T tid ) ; extern void MdlUpdateTID3 ( int_T
tid ) ; extern void MdlUpdateTID4 ( int_T tid ) ; extern void MdlOutputsTID2
( int_T tid ) ; extern void MdlOutputsTID3 ( int_T tid ) ; extern void
MdlOutputsTID4 ( int_T tid ) ; extern const rtwCAPI_ModelMappingStaticInfo *
SistemaEstanques_PID_discreto_GetCAPIStaticMap ( void ) ; extern SimStruct *
const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
