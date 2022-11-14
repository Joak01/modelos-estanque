#include "SistemaEstanques_PID_discreto.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "SistemaEstanques_PID_discreto_private.h"
#include "rt_logging_mmi.h"
#include "SistemaEstanques_PID_discreto_capi.h"
#include "SistemaEstanques_PID_discreto_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 5 , & stopRequested ) ; }
rtExtModeShutdown ( 5 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 6 ; const char_T
* gbl_raccel_Version = "10.5 (R2022a) 13-Nov-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi
; uint32_T lo ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if
( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T si ; real_T sr ; real_T
y ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MdlInitialize ( void ) { rtX . n5jaiqo4q1 = rtP .
SistemadeEstanques_T0c ; rtX . oijbjoorjx = rtP . SistemadeEstanques_T0r ;
rtX . kq0qmjau05 = rtP . SistemadeEstanques_h0 + 1.0E-6 ; rtDW . cijhhdchyo =
false ; rtDW . hxixz0diaj = 0U ; rtDW . ik50j3b4la = false ; rtDW .
phkyglsksj = 0U ; rtDW . ercrtsl3ul = false ; rtDW . fkpuglvoce = 0U ; rtDW .
ajg1qa13qd = false ; rtDW . mxczgh10dw = 0U ; rtDW . no0onatjsa = false ;
rtDW . nhjl40zo3t = 0U ; rtDW . f1vped4bnl = false ; rtDW . pvkjz3veq1 = 0U ;
rtDW . o0b14vit54 = false ; rtDW . mfqkf0zqeo = 0U ; rtDW . ltv1e4zdnf =
false ; rtDW . ksfiloike2 = 0U ; rtDW . cbpmfl3daa = false ; rtDW .
l2kheao0b5 = 0U ; rtDW . ihzo0v2eqx = false ; rtDW . kbdgvwackz = 0U ; rtDW .
opu3gm1und = false ; rtDW . lbxi5wwnx3 = 0U ; rtDW . loyc4qmd00 = false ;
rtDW . hc55zqdtz0 = 0U ; rtDW . dlka5jhs0h = false ; rtDW . mqicor4wcz = 0U ;
rtDW . ccq1r4uodm = false ; rtDW . h0wbwp43sy = 0U ; rtDW . eeyqmg1sps =
false ; rtDW . n3yhdhd3sz = 0U ; rtDW . aiqbe2qv5w = false ; rtDW .
bbtqzyjvdv = 0U ; rtDW . arn25zbrew = false ; rtDW . nr0mtfjxwf = 0U ; rtDW .
k4odt4vyi3 = false ; rtDW . dzabhw2v3z = 0U ; rtDW . f1gmat2bv1 = rtP .
PIDController_InitialConditionForIntegrator ; rtDW . dwaftwnef5 = rtP .
PIDController_InitialConditionForFilter ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Product" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Product" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/To Workspace" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Product" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. n2alg3gtxb . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"33c222e9-bd67-46c0-820c-5fafac6af315" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . n2alg3gtxb . AQHandles , hDT , & srcInfo ) ; if ( rtDW . n2alg3gtxb .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . n2alg3gtxb . AQHandles ,
"0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
n2alg3gtxb . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n2alg3gtxb .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . n2alg3gtxb . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . n2alg3gtxb . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . n2alg3gtxb . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"f_out" ) ; sdiRegisterWksVariable ( rtDW . n2alg3gtxb . AQHandles , varName
, "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Saturation1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Saturation1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/To Workspace2" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Saturation1" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. pkvrcopyel . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"8aa40378-6b20-4379-b0ad-3e878ba3ba1d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . pkvrcopyel . AQHandles , hDT , & srcInfo ) ; if ( rtDW . pkvrcopyel .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . pkvrcopyel . AQHandles ,
"0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pkvrcopyel . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . pkvrcopyel .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . pkvrcopyel . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . pkvrcopyel . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pkvrcopyel . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"coef_falla_2" ) ; sdiRegisterWksVariable ( rtDW . pkvrcopyel . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Saturation2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Saturation2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/To Workspace3" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Saturation2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. ny23d4etja . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"7a3dbb1f-5c92-4bab-86bf-c7042fed3d1d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . ny23d4etja . AQHandles , hDT , & srcInfo ) ; if ( rtDW . ny23d4etja .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ny23d4etja . AQHandles ,
"0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
ny23d4etja . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ny23d4etja .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . ny23d4etja . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . ny23d4etja . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . ny23d4etja . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"coef_falla_3" ) ; sdiRegisterWksVariable ( rtDW . ny23d4etja . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Divide" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Divide" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/To Workspace5" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Divide" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. f2mr0nuv1k . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"ecde6d6d-eda0-4ebe-bca3-b507c6bab568" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . f2mr0nuv1k . AQHandles , hDT , & srcInfo ) ; if ( rtDW . f2mr0nuv1k .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . f2mr0nuv1k . AQHandles ,
"0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
f2mr0nuv1k . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . f2mr0nuv1k .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . f2mr0nuv1k . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . f2mr0nuv1k . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . f2mr0nuv1k . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"actual_hc_hat" ) ; sdiRegisterWksVariable ( rtDW . f2mr0nuv1k . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Waveform\nGenerator" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Waveform\nGenerator" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SistemaEstanques_PID_discreto/To Workspace" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Waveform\nGenerator" ) ; sdiAsyncRepoDataTypeHandle
hDT = sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; {
sdiComplexity sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1
; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. n2alg3gtxbm . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"3fc51dc2-8db9-4870-8da5-d87e34d226f5" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . n2alg3gtxbm . AQHandles , hDT , & srcInfo ) ; if ( rtDW . n2alg3gtxbm
. AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . n2alg3gtxbm . AQHandles
, "1" , 1.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
n2alg3gtxbm . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n2alg3gtxbm .
AQHandles , ssGetTaskTime ( rtS , 3 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . n2alg3gtxbm . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName
( rtDW . n2alg3gtxbm . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . n2alg3gtxbm . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"REFERENCIA" ) ; sdiRegisterWksVariable ( rtDW . n2alg3gtxbm . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Sistema de Estanques:1" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Sistema de Estanques:1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SistemaEstanques_PID_discreto/To Workspace1" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Sistema de Estanques:1" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . avu4vt3ihx . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "11b34ad6-1850-4dd1-8ba0-1c5fac187958" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . avu4vt3ihx . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . avu4vt3ihx . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . avu4vt3ihx . AQHandles , "1" , 1.0 ,
ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . avu4vt3ihx . AQHandles ,
0.0 ) ; sdiSetRunStartTime ( rtDW . avu4vt3ihx . AQHandles , ssGetTaskTime (
rtS , 3 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . avu4vt3ihx .
AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . avu4vt3ihx .
AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . avu4vt3ihx . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Actual_hc" ) ; sdiRegisterWksVariable ( rtDW . avu4vt3ihx . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "PID Controller" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "PID Controller" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SistemaEstanques_PID_discreto/To Workspace2" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "PID Controller" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. pkvrcopyelh . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"25146941-d0d1-4d8b-8133-0f58187073f8" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . pkvrcopyelh . AQHandles , hDT , & srcInfo ) ; if ( rtDW . pkvrcopyelh
. AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . pkvrcopyelh . AQHandles
, "1" , 1.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pkvrcopyelh . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . pkvrcopyelh .
AQHandles , ssGetTaskTime ( rtS , 3 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . pkvrcopyelh . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName
( rtDW . pkvrcopyelh . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pkvrcopyelh . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"f_pid" ) ; sdiRegisterWksVariable ( rtDW . pkvrcopyelh . AQHandles , varName
, "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Zero-Order\nHold2" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Zero-Order\nHold2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SistemaEstanques_PID_discreto/To Workspace3" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Zero-Order\nHold2" ) ; sdiAsyncRepoDataTypeHandle hDT
= sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. ny23d4etjaa . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"fe97d8f1-32d3-41a1-8284-3cf3a958d06b" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . ny23d4etjaa . AQHandles , hDT , & srcInfo ) ; if ( rtDW . ny23d4etjaa
. AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ny23d4etjaa . AQHandles
, "1" , 1.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
ny23d4etjaa . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ny23d4etjaa .
AQHandles , ssGetTaskTime ( rtS , 3 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . ny23d4etjaa . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName
( rtDW . ny23d4etjaa . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . ny23d4etjaa . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Mesuared_hc" ) ; sdiRegisterWksVariable ( rtDW . ny23d4etjaa . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Saturation" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Saturation" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/To Workspace1" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Saturation" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. avu4vt3ihx4 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"3be50768-838a-48d0-95a0-ce23d3e09bf4" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . avu4vt3ihx4 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . avu4vt3ihx4
. AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . avu4vt3ihx4 . AQHandles
, "1" , 1.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
avu4vt3ihx4 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . avu4vt3ihx4 .
AQHandles , ssGetTaskTime ( rtS , 3 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . avu4vt3ihx4 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName
( rtDW . avu4vt3ihx4 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . avu4vt3ihx4 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"coef_falla_1" ) ; sdiRegisterWksVariable ( rtDW . avu4vt3ihx4 . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Saturador1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Saturador1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/To Workspace4" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Saturador1" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. n52vpgrthw . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"177fb94e-0335-4ad3-993a-8b38c6a6cf6d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . n52vpgrthw . AQHandles , hDT , & srcInfo ) ; if ( rtDW . n52vpgrthw .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . n52vpgrthw . AQHandles ,
"15" , 15.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . n52vpgrthw
. AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n52vpgrthw . AQHandles ,
ssGetTaskTime ( rtS , 4 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
n52vpgrthw . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
n52vpgrthw . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . n52vpgrthw . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"freq_interna" ) ; sdiRegisterWksVariable ( rtDW . n52vpgrthw . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } MdlInitialize
( ) ; } void MdlOutputs ( int_T tid ) { real_T axazuvueab ; real_T kcnqhi2x1t
; real_T kgqmtg45bz ; real_T nq0ehu412i ; if ( ssIsContinuousTask ( rtS , 0 )
) { rtB . m2w3hx33rl = rtX . n5jaiqo4q1 ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { } rtB . ga0bmsoaao = rtX . oijbjoorjx ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { } if ( ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtX . kq0qmjau05 >= rtP
. Integrador_UpperSat ) { if ( rtX . kq0qmjau05 != rtP . Integrador_UpperSat
) { rtX . kq0qmjau05 = rtP . Integrador_UpperSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } else if ( ( rtX .
kq0qmjau05 <= rtP . Integrador_LowerSat ) && ( rtX . kq0qmjau05 != rtP .
Integrador_LowerSat ) ) { rtX . kq0qmjau05 = rtP . Integrador_LowerSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . kqhghyeq3z = rtX
. kq0qmjau05 ; } else if ( rtX . kq0qmjau05 >= rtP . Integrador_UpperSat ) {
rtB . kqhghyeq3z = rtP . Integrador_UpperSat ; } else if ( rtX . kq0qmjau05
<= rtP . Integrador_LowerSat ) { rtB . kqhghyeq3z = rtP . Integrador_LowerSat
; } else { rtB . kqhghyeq3z = rtX . kq0qmjau05 ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtB . pbcmo2oung = rtB . amqerpar2b ; } axazuvueab =
muDoubleScalarSqrt ( rtB . kqhghyeq3z ) ; rtB . hlxlc4tizq = ( rtP .
beta_Gain * axazuvueab + axazuvueab * rtB . pbcmo2oung ) * ( 1.0 - rtP .
SistemadeEstanques_Fout_null ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtDW . n2alg3gtxb . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . n2alg3gtxb . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . hlxlc4tizq + 0 ) ; } } } } if
( ssGetTaskTime ( rtS , 0 ) < rtP . Ramp1_start ) { axazuvueab = rtP .
Step_Y0 ; } else { axazuvueab = rtP . Ramp1_slope ; } nq0ehu412i = ( ssGetT (
rtS ) - rtP . Ramp1_start ) * axazuvueab + rtP . Ramp1_InitialOutput ; if (
nq0ehu412i > rtP . Saturation1_UpperSat ) { rtB . pamg2ltvgy = rtP .
Saturation1_UpperSat ; } else if ( nq0ehu412i < rtP . Saturation1_LowerSat )
{ rtB . pamg2ltvgy = rtP . Saturation1_LowerSat ; } else { rtB . pamg2ltvgy =
nq0ehu412i ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( rtDW . pkvrcopyel . AQHandles && ssGetLogOutput ( rtS
) ) { sdiWriteSignal ( rtDW . pkvrcopyel . AQHandles , ssGetTaskTime ( rtS ,
1 ) , ( char * ) & rtB . pamg2ltvgy + 0 ) ; } } } } if ( ssGetTaskTime ( rtS
, 0 ) < rtP . Ramp2_start ) { axazuvueab = rtP . Step_Y0_h2h1sloxcm ; } else
{ axazuvueab = rtP . Ramp2_slope ; } nq0ehu412i = ( ssGetT ( rtS ) - rtP .
Ramp2_start ) * axazuvueab + rtP . Ramp2_InitialOutput ; if ( nq0ehu412i >
rtP . Saturation2_UpperSat ) { rtB . lku50azrkb = rtP . Saturation2_UpperSat
; } else if ( nq0ehu412i < rtP . Saturation2_LowerSat ) { rtB . lku50azrkb =
rtP . Saturation2_LowerSat ; } else { rtB . lku50azrkb = nq0ehu412i ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( rtDW . ny23d4etja . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal
( rtDW . ny23d4etja . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) &
rtB . lku50azrkb + 0 ) ; } } } rtB . ggov1pk5jg = rtB . p2gs34a42l ; rtB .
otvgwe1e1e = rtB . cawe1pel2l ; } nq0ehu412i = ( ( rtB . otvgwe1e1e * rtB .
pamg2ltvgy + rtB . ggov1pk5jg ) + rtB . lku50azrkb ) + rtP . C2_Value ; if (
nq0ehu412i > rtP . Saturador2_UpperSat ) { nq0ehu412i = rtP .
Saturador2_UpperSat ; } else if ( nq0ehu412i < rtP . Saturador2_LowerSat ) {
nq0ehu412i = rtP . Saturador2_LowerSat ; } rtB . eicjvshfeq = ( nq0ehu412i -
rtB . hlxlc4tizq ) / ( ( rtB . kqhghyeq3z * rtB . kqhghyeq3z * rtP . uK1_Gain
+ rtP . uK2_Gain * rtB . kqhghyeq3z ) + rtP . K3_Value ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { { if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtDW .
f2mr0nuv1k . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
f2mr0nuv1k . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
eicjvshfeq + 0 ) ; } } } } if ( ( rtB . kqhghyeq3z < 0.0 ) && ( rtP .
Constant1_Value_pxdhqqllht > muDoubleScalarFloor ( rtP .
Constant1_Value_pxdhqqllht ) ) ) { axazuvueab = - muDoubleScalarPower ( - rtB
. kqhghyeq3z , rtP . Constant1_Value_pxdhqqllht ) ; } else { axazuvueab =
muDoubleScalarPower ( rtB . kqhghyeq3z , rtP . Constant1_Value_pxdhqqllht ) ;
} axazuvueab = ( ( rtB . kqhghyeq3z * rtB . kqhghyeq3z * rtP . Gain1_Gain +
rtP . Gain_Gain * axazuvueab ) + rtP . Gain2_Gain * rtB . kqhghyeq3z ) + rtP
. Constant_Value_nh4qnxlmtb ; kgqmtg45bz = rtB . m2w3hx33rl - rtP .
Constant_Value ; kcnqhi2x1t = rtB . kqhghyeq3z * rtB . kqhghyeq3z ; rtB .
bnnrwyns0c = ( ( rtP . cp_Value * rtP . rho_Value * nq0ehu412i * ( rtB .
ga0bmsoaao - rtB . m2w3hx33rl ) - rtP . ha_Value * rtP . constant_Value *
kcnqhi2x1t * kgqmtg45bz ) - rtP . km_Value * rtP . constant1_Value *
kcnqhi2x1t * kgqmtg45bz ) / ( rtP . cp1_Value * rtP . rho1_Value * axazuvueab
) ; nq0ehu412i = rtB . ga0bmsoaao - rtP . Constant_Value ; rtB . kv0eqywsiz =
( ( ( rtP . cp_Value_eh2zrr2jtp * rtP . rho_Value_k2fdqeovty * rtB .
hlxlc4tizq * ( rtB . m2w3hx33rl - rtB . ga0bmsoaao ) + rtP . Constant1_Value
) - rtP . ha_Value_llewwjyayt * rtP . constant_Value_dbb4dojqmp * nq0ehu412i
) - ( rtP . Gain_Gain_okzxc23qf2 * rtB . kqhghyeq3z + rtP . km1_Value ) * rtP
. km_Value_feeasfdogm * nq0ehu412i ) / ( ( rtP . M_Value - rtP .
rho1_Value_oipnu5fd53 * axazuvueab ) * rtP . cp1_Value_hzyk4t5t4c ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . mjd1ansmc2 = rtB . ns50kkurdv ; } rtB
. m4eclbfi40 = rtB . kqhghyeq3z + rtB . mjd1ansmc2 ; } if ( ssIsSampleHit (
rtS , 2 , 0 ) ) { MdlOutputsTID2 ( tid ) ; } if ( ssIsSampleHit ( rtS , 3 , 0
) ) { MdlOutputsTID3 ( tid ) ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
MdlOutputsTID4 ( tid ) ; } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 (
int_T tid ) { real_T applyStandardDeviation ; real_T applyStandardDeviation_e
; real_T applyStandardDeviation_f ; real_T applyStandardDeviation_g ; real_T
applyStandardDeviation_i ; real_T applyStandardDeviation_j ; real_T
applyStandardDeviation_m ; real_T applyStandardDeviation_p ; real_T
bkywyomtj0 ; int32_T tmp ; int32_T tmp_ap ; int32_T tmp_b ; int32_T tmp_b0 ;
int32_T tmp_c ; int32_T tmp_cc ; int32_T tmp_ck ; int32_T tmp_d ; int32_T
tmp_d0 ; int32_T tmp_dz ; int32_T tmp_e ; int32_T tmp_f ; int32_T tmp_f2 ;
int32_T tmp_fs ; int32_T tmp_fv ; int32_T tmp_g ; int32_T tmp_hn ; int32_T
tmp_i ; int32_T tmp_j ; int32_T tmp_k ; int32_T tmp_kh ; int32_T tmp_kt ;
int32_T tmp_l ; int32_T tmp_lt ; int32_T tmp_m ; int32_T tmp_m0 ; int32_T
tmp_m4 ; int32_T tmp_mi ; int32_T tmp_n ; int32_T tmp_nf ; int32_T tmp_o ;
int32_T tmp_p ; int32_T tmp_pj ; int32_T tmp_pk ; int32_T tmp_po ; switch ( (
int32_T ) rtP . WaveformGenerator_SelectedSignal_f3od4jcqqc ) { case 1 :
tmp_hn = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ssGetTaskTime ( rtS , 2 ) >= 0.0 ? 40 : 0 ) + (
ssGetTaskTime ( rtS , 2 ) >= 400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 1200.0 ? - 17 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 1600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 2000.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2800.0 ? 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 3200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 3600.0
? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4000.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 4400.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 4800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 5200.0 ? - 35 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 5600.0 ? 19 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 6000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6400.0 ? -
9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6800.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 7200.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 7600.0 ? 19 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8000.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 8400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 8800.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 9200.0 ? - 37 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 9600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 10000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10400.0 ? 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10800.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 11200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 11600.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12000.0 ? 37 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 12800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 13200.0
? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 13600.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 14000.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 14400.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14800.0 ? - 37 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 15200.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 15600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 16000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 16400.0 ? - 21 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 16800.0 ? 11 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 17200.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17600.0 ?
- 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18000.0 ? 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 18400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 18800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 19200.0 ? - 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 19600.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 20000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 20400.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20800.0 ? 18 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21200.0 ? 11 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 21600.0 ? - 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
22000.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22400.0 ? - 7 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 22800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 23200.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 23600.0 ? - 42 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 24400.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 24800.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25200.0 ? - 30 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25600.0 ? 13 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 26000.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26400.0 ? 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26800.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 27200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
27600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28000.0 ? - 8 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 28400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 28800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29200.0 ? 24 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29600.0 ? 3 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 30000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
30400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 30800.0 ? - 3 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 31200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 31600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32000.0 ? - 14 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32400.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 32800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 33200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 33600.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 34400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34800.0 ?
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 35200.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 35600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 36000.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 36400.0 ? 6 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 36800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 37200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 37600.0 ?
- 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 38400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 38800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39200.0 ? 21 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39600.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 40000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 40400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 40800.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 41200.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 41600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42000.0 ?
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42400.0 ? - 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 42800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 43200.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 43600.0 ? - 17 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44000.0 ? 15 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 44400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44800.0
? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 45200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 46000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 46800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 47200.0 ? - 28 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 47600.0 ? 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 48000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48400.0 ? 35 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 48800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 49200.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 49600.0
? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50000.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 50400.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 50800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 51200.0 ? 9 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 51600.0 ? - 2 : 0 ) ; tmp_ap = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( tmp_hn + ( ssGetTaskTime ( rtS , 2 ) >= 52000.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 52400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 52800.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 53200.0 ? 36 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 53600.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 54000.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 54400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 54800.0 ? 3 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 55200.0 ? 18 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 55600.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56000.0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56400.0 ? 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 56800.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 57200.0 ?
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 57600.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 58000.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 58400.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 58800.0 ? 13 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 59200.0 ? 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 59600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
60000.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 60400.0 ? - 9 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 60800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 61200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 61600.0 ? - 47
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62000.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 62400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 62800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 63200.0 ? - 28 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 63600.0 ? 34 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 64000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64400.0
? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64800.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 65200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 66000.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66400.0 ? - 20 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66800.0 ? 27 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 67200.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
67600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68000.0 ? 24 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 68400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 68800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69200.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69600.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 70000.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 70400.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 70800.0 ? 38 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71200.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 71600.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 72000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72400.0 ? 33 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72800.0 ? - 48 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 73200.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 73600.0
? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74000.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 74400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 74800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75200.0 ? - 27 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75600.0 ? 14 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 76000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76400.0
? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76800.0 ? 46 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 77200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 78000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78400.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78800.0 ? - 38 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 79200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 79600.0
? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 80000.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 80400.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 80800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 81200.0 ? - 19 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82000.0 ? 20 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 82400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82800.0
? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 83200.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 83600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 84000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84400.0 ? 31 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84800.0 ? 4 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 85200.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 85600.0
? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 86000.0 ? 48 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 86400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 86800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87200.0 ? - 28 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87600.0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 88000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88400.0 ? 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88800.0 ? 27 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 89200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 89600.0
? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90000.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 90400.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 90800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 91200.0 ? - 24 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 91600.0 ? 31 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 92000.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92400.0 ?
- 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92800.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 93200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 93600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94000.0 ? 21 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94400.0 ? - 15 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 94800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 95200.0
? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 95600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 96000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 96400.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96800.0 ? 9 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 97200.0 ? 14 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 98000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98400.0
? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98800.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 99200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 99600.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100000.0 ? 25
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100400.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 100800.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 101200.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 101600.0 ? 30 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102000.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 102400.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 102800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103200.0 ? - 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103600.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 104000.0 ? 24 : 0 ) ; tmp_pj = ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
tmp_ap + ( ssGetTaskTime ( rtS , 2 ) >= 104400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 104800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 105200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 105600.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 106000.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 106400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 106800.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107200.0 ? - 37 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107600.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 108000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 108400.0 ? 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 108800.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 109200.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 109600.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 110000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110400.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110800.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 111200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 111600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112000.0 ? -
29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 112800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 113200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 113600.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 114000.0 ? 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 114400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 114800.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115200.0 ?
17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115600.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 116000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 116400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 116800.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 117200.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 117600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 118000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118400.0 ? - 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118800.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 119200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 119600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120000.0 ? - 18 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120400.0 ? 6 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 120800.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
121200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 121600.0 ? - 27 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 122000.0 ? 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 122400.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 122800.0
? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 123200.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 123600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 124000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 124400.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 124800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 125200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 125600.0 ?
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126000.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 126400.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 126800.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 127600.0 ? -
8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 128400.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 128800.0 ? - 43 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 129200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 129600.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 130000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 130400.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 130800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131200.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131600.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 132000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 132400.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132800.0 ? - 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 133200.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 133600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 134000.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134400.0 ? 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134800.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 135200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 135600.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136000.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136400.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 136800.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 137200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137600.0 ? -
6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 138000.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 138400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 138800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 139200.0 ? 22 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 139600.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 140000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
140400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140800.0 ? 26 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 141200.0 ? - 5 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 141600.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
142000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 142400.0 ? 7 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 142800.0 ? 19 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 143200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143600.0
? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 144000.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 144400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 144800.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145200.0 ? 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145600.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 146000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 146400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 146800.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 147200.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 147600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 148000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148400.0 ? 33 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148800.0 ? - 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 149200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 149600.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150000.0 ? - 23 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150400.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 150800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 151200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 151600.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152000.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 152400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152800.0 ? 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 153200.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 153600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 154000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154400.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154800.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 155200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 155600.0 ? 14 : 0 ) ; tmp_po = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_pj + (
ssGetTaskTime ( rtS , 2 ) >= 156000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 156400.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 156800.0 ? 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 157200.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 157600.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 158000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158400.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158800.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 159200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 159600.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160400.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 160800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 161200.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 161600.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 162000.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 162400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 162800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 163200.0 ? 26
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 163600.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 164000.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 164400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164800.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 165200.0 ? 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 165600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 166000.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166400.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166800.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 167200.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 167600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168000.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168400.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 168800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 169200.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 169600.0 ? - 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 170000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 170400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 170800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171200.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171600.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 172000.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 172400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 172800.0 ? - 9 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 173200.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 173600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 174000.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174400.0 ? -
35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174800.0 ? 42 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 175200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
175600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176000.0 ? 31 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 176400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 176800.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
177200.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 177600.0 ? - 19 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 178000.0 ? - 30 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 178400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 178800.0
? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 179200.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 179600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 180000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180400.0 ? -
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 181200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 181600.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182000.0 ? 42
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182400.0 ? - 49 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 182800.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 183200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 183600.0 ? - 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 184000.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 184400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 184800.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185200.0 ? 21
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185600.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 186000.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 186400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 186800.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 187200.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 187600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 188000.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188400.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 189200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 189600.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190000.0 ? -
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190400.0 ? 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 190800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 191200.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 191600.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 192000.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 192400.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 192800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193200.0 ? -
34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 194000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 194400.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 194800.0 ? 13 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 195200.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 195600.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 196000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196400.0 ? - 35
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196800.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 197200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 197600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198000.0 ? - 29
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198800.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 199200.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 199600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200000.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200400.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 200800.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 201200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 201600.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 202000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 202400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 202800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 203200.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 203600.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 204000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 204800.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 205200.0 ? - 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 205600.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 206000.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 206400.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 206800.0 ? 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 207200.0 ? - 25 : 0 ) ; tmp_pk = ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( tmp_po + ( ssGetTaskTime ( rtS , 2 ) >= 207600.0 ? 8 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 208000.0 ? - 25 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 208400.0 ? 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 208800.0
? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 209200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 209600.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 210000.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210400.0 ? - 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210800.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 211200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 211600.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212000.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 212800.0 ? 39 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 213200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 213600.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 214000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 214400.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 214800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215200.0 ? - 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 216000.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 216400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216800.0 ? -
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 217200.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 217600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 218000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218400.0 ? - 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218800.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 219200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 219600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220000.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220400.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 220800.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 221200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 221600.0 ? - 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222000.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 222400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 222800.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 223200.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 223600.0 ? - 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 224000.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 224400.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224800.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 225200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 225600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 226000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 226800.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 227200.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 227600.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 228000.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228400.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228800.0 ? 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 229200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 229600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230000.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230400.0 ? 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 230800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
231200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 231600.0 ? - 24 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 232000.0 ? 6 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 232400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
232800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 233200.0 ? 24 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 233600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 234000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234400.0
? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 235200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 235600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236000.0 ? 32 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236400.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 236800.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 237200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 237600.0 ? -
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238000.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 238400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 238800.0 ? - 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239200.0 ? 31 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239600.0 ? 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 240000.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
240400.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 240800.0 ? - 21 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 241200.0 ? 38 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 241600.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
242000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 242400.0 ? - 13 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 242800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 243200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
243600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 244000.0 ? - 19 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 244400.0 ? 11 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 244800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 245200.0 ?
- 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 245600.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 246000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 246400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246800.0 ? - 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 247200.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 247600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 248000.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248400.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248800.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 249600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 250000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250400.0 ? - 25
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250800.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 251200.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 251600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252000.0 ?
15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252400.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 252800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 253200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 253600.0 ? - 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 254000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 254400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 254800.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255200.0 ? - 48
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255600.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 256000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 256400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 256800.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 257200.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 257600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 258000.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258400.0 ? 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258800.0 ? - 5 : 0 ) ; tmp_d0 = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( tmp_pk + ( ssGetTaskTime ( rtS , 2 ) >= 259200.0 ? - 29 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 259600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 260000.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260400.0 ?
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260800.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 261200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 261600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262000.0 ? 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262400.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 262800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 263200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 263600.0 ? 10 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 264000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 264400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 264800.0
? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 265200.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 265600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 266000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266400.0 ? 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266800.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 267200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 267600.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268000.0 ? 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268400.0 ? - 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 268800.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 269200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 269600.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 270000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 270400.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 270800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271200.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271600.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 272000.0 ? - 46 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 272400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 272800.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 273200.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 273600.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 274000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274400.0 ? 28
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274800.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 275200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 275600.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276000.0 ? 38 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276400.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 276800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 277200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 277600.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 278000.0 ? - 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 278400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 278800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279200.0 ? 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279600.0 ? 24 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 280000.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
280400.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 280800.0 ? - 20 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 281200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 281600.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282000.0
? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 283200.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 283600.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284000.0 ? 34
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 284800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 285200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 285600.0 ? 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 286000.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 286400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 286800.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287200.0 ? -
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287600.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 288000.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 288400.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289200.0 ? - 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289600.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 290000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 290400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 290800.0 ? 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 291200.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 291600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 292000.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292400.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292800.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 293200.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 293600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294000.0 ?
41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294400.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 294800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 295200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 295600.0 ? -
1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 296000.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 296400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 296800.0 ? 50 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297200.0 ? - 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297600.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 298000.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 298400.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 298800.0 ? -
26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 299200.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 299600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 300000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300800.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 301200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 301600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302000.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302400.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 302800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 303200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 303600.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 304000.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 304400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 304800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305200.0 ?
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305600.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 306000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 306400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306800.0 ? 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 307200.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 307600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 308000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308400.0 ? - 37
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308800.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 309200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 309600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310000.0 ? 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310400.0 ? - 8 : 0 ) ; tmp_kh = ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( tmp_d0 + ( ssGetTaskTime ( rtS , 2 ) >= 310800.0 ? 2 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 311200.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 311600.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 312000.0 ? -
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 312800.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 313200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 313600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314000.0 ? -
8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314400.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 314800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 315200.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 315600.0 ? 31 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316000.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 316400.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 316800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 317200.0 ? - 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 317600.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 318000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 318400.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318800.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 319200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 319600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320000.0
? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320400.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 320800.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 321200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 321600.0 ? -
21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 322000.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 322400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 322800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323200.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323600.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 324000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 324400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324800.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 325200.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 325600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 326000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326400.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 327200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 327600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328000.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328400.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 328800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 329200.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 329600.0 ?
24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 330000.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 330400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 330800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 331200.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 331600.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 332000.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 332400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332800.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 333200.0 ? 42 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 333600.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 334000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334400.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334800.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 335200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 335600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336000.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336400.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 336800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 337200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 337600.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338000.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 338400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 338800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 339200.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 339600.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 340000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 340400.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 340800.0 ? 15 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341200.0 ? - 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 341600.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 342000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342400.0 ? 22 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342800.0 ? - 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 343200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 343600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344000.0 ? 26 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344400.0 ? 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 344800.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
345200.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 345600.0 ? - 42 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 346000.0 ? 46 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 346400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
346800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 347200.0 ? 22 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 347600.0 ? - 18 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 348000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348400.0
? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348800.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 349200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 349600.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350000.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350400.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 350800.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 351200.0 ? - 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 351600.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352000.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 352400.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 352800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 353200.0 ? 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 353600.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 354000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 354400.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354800.0 ? -
38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 355200.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 355600.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 356000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356400.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 357200.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 357600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358000.0 ? 16 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358400.0 ? 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 358800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
359200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 359600.0 ? - 20 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 360000.0 ? - 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 360400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 360800.0 ?
- 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 361200.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 361600.0 ? - 7 : 0 ) ; rtB . c2nnsvritk = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( real_T ) ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( tmp_kh + ( ssGetTaskTime ( rtS , 2 ) >= 362000.0 ? 10 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 362400.0 ? 14 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 362800.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
363200.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 363600.0 ? 11 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 364000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 364400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 364800.0 ?
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 365200.0 ? - 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 365600.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 366000.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366400.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366800.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 367200.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 367600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368000.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368400.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 368800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 369200.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 369600.0 ? -
29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 370000.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 370400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 370800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371200.0 ? 2 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371600.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 372000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 372400.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372800.0 ? -
22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 373200.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 373600.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 374000.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374400.0 ? 4 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374800.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 375200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 375600.0 ? - 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 377200.0 ? 2.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 377600.0 ? 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378000.0
? 14.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378400.0 ? - 14.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 378800.0 ? - 25.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 379200.0 ? 42.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 379600.0 ? - 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
380000.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380400.0 ? 2.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380800.0 ? - 23.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 381200.0 ? 27.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 381600.0 ? - 26.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
382000.0 ? 9.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382400.0 ? 13.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382800.0 ? 4.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 383200.0 ? - 21.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 383600.0 ? 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
384000.0 ? - 19.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384400.0 ? - 9.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384800.0 ? 25.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 385200.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 385600.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
386000.0 ? 36.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386400.0 ? - 30.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386800.0 ? 11.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 387200.0 ? - 17.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 387600.0 ? 20.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
388000.0 ? - 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388400.0 ? - 4.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388800.0 ? - 1.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 389200.0 ? 18.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 389600.0 ? - 14.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
390000.0 ? - 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390400.0 ? 12.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390800.0 ? - 24.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 391200.0 ? 21.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 391600.0 ? 12.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
392000.0 ? - 30.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392400.0 ? 35.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392800.0 ? - 44.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 393200.0 ? 6.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 393600.0 ? 30.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394000.0
? 7.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394400.0 ? - 28.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 394800.0 ? - 10.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 395200.0 ? 6.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 395600.0 ? 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396000.0
? 16.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396400.0 ? - 16.0 : 0.0 ) ;
break ; case 2 : rtB . c2nnsvritk = ssGetTaskTime ( rtS , 2 ) >= 0.0 ? 25.0 :
0.0 ; break ; case 3 : tmp = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ssGetTaskTime ( rtS , 2 )
>= 0.0 ? 40 : 0 ) + ( ssGetTaskTime ( rtS , 2 ) >= 400.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 )
>= 1200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 1600.0 ? - 16 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 2000.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 2400.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2800.0 ? 5 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 3200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 3600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4000.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4400.0 ? 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 4800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 5200.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 5600.0 ? 19 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 6000.0 ? 17 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 6400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6800.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 7200.0 ? - 16 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 7600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8000.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8400.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 8800.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 9200.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 9600.0 ? 7 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 10000.0 ? 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 10400.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10800.0 ?
- 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 11200.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 11600.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 12000.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12400.0 ? - 5 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 13200.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
13600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14000.0 ? - 25 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 14400.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 14800.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 15200.0 ? -
9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 15600.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 16000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 16400.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 16800.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17200.0 ? 26 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 17600.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18000.0
? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18400.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 18800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 19200.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 19600.0 ? 38 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20000.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 20400.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 20800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21200.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21600.0 ? - 45 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 22000.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22400.0
? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22800.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 23200.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 23600.0 ? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24000.0 ? - 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24400.0 ? 13 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 24800.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25200.0
? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25600.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 26000.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 26400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26800.0 ? - 14 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 27200.0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 27600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28000.0 ? - 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28400.0 ? 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 28800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29200.0
? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29600.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 30000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 30400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 30800.0 ? - 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 31200.0 ? 9 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 31600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32000.0
? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32400.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 32800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 33200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 33600.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 34400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34800.0 ?
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 35200.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 35600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 36000.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 36400.0 ? 6 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 36800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 37200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 37600.0 ?
- 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 38400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 38800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39200.0 ? 21 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39600.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 40000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 40400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 40800.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 41200.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 41600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42000.0 ?
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42400.0 ? - 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 42800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 43200.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 43600.0 ? - 17 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44000.0 ? 15 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 44400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44800.0
? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 45200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 46000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 46800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 47200.0 ? - 28 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 47600.0 ? 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 48000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48400.0 ? 35 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 48800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 49200.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 49600.0
? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50000.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 50400.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 50800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 51200.0 ? 9 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 51600.0 ? - 2 : 0 ) ; tmp_p = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( tmp + ( ssGetTaskTime ( rtS , 2 ) >= 52000.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 52400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 52800.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 53200.0 ? 36 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 53600.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 54000.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 54400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 54800.0 ? 3 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 55200.0 ? 18 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 55600.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56000.0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56400.0 ? 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 56800.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 57200.0 ?
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 57600.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 58000.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 58400.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 58800.0 ? 13 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 59200.0 ? 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 59600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
60000.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 60400.0 ? - 9 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 60800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 61200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 61600.0 ? - 47
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62000.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 62400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 62800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 63200.0 ? - 28 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 63600.0 ? 34 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 64000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64400.0
? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64800.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 65200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 66000.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66400.0 ? - 20 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66800.0 ? 27 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 67200.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
67600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68000.0 ? 24 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 68400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 68800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69200.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69600.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 70000.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 70400.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 70800.0 ? 38 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71200.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 71600.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 72000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72400.0 ? 33 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72800.0 ? - 48 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 73200.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 73600.0
? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74000.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 74400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 74800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75200.0 ? - 27 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75600.0 ? 14 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 76000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76400.0
? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76800.0 ? 46 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 77200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 78000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78400.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78800.0 ? - 38 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 79200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 79600.0
? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 80000.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 80400.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 80800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 81200.0 ? - 19 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82000.0 ? 20 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 82400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82800.0
? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 83200.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 83600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 84000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84400.0 ? 31 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84800.0 ? 4 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 85200.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 85600.0
? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 86000.0 ? 48 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 86400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 86800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87200.0 ? - 28 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87600.0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 88000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88400.0 ? 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88800.0 ? 27 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 89200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 89600.0
? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90000.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 90400.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 90800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 91200.0 ? - 24 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 91600.0 ? 31 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 92000.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92400.0 ?
- 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92800.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 93200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 93600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94000.0 ? 21 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94400.0 ? - 15 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 94800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 95200.0
? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 95600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 96000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 96400.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96800.0 ? 9 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 97200.0 ? 14 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 98000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98400.0
? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98800.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 99200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 99600.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100000.0 ? 25
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100400.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 100800.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 101200.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 101600.0 ? 30 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102000.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 102400.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 102800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103200.0 ? - 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103600.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 104000.0 ? 24 : 0 ) ; tmp_e = ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
tmp_p + ( ssGetTaskTime ( rtS , 2 ) >= 104400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 104800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 105200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 105600.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 106000.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 106400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 106800.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107200.0 ? - 37 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107600.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 108000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 108400.0 ? 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 108800.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 109200.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 109600.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 110000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110400.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110800.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 111200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 111600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112000.0 ? -
29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 112800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 113200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 113600.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 114000.0 ? 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 114400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 114800.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115200.0 ?
17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115600.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 116000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 116400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 116800.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 117200.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 117600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 118000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118400.0 ? - 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118800.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 119200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 119600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120000.0 ? - 18 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120400.0 ? 6 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 120800.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
121200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 121600.0 ? - 27 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 122000.0 ? 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 122400.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 122800.0
? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 123200.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 123600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 124000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 124400.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 124800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 125200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 125600.0 ?
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126000.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 126400.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 126800.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 127600.0 ? -
8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 128400.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 128800.0 ? - 43 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 129200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 129600.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 130000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 130400.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 130800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131200.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131600.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 132000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 132400.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132800.0 ? - 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 133200.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 133600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 134000.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134400.0 ? 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134800.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 135200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 135600.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136000.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136400.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 136800.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 137200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137600.0 ? -
6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 138000.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 138400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 138800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 139200.0 ? 22 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 139600.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 140000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
140400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140800.0 ? 26 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 141200.0 ? - 5 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 141600.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
142000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 142400.0 ? 7 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 142800.0 ? 19 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 143200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143600.0
? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 144000.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 144400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 144800.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145200.0 ? 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145600.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 146000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 146400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 146800.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 147200.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 147600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 148000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148400.0 ? 33 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148800.0 ? - 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 149200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 149600.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150000.0 ? - 23 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150400.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 150800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 151200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 151600.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152000.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 152400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152800.0 ? 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 153200.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 153600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 154000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154400.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154800.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 155200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 155600.0 ? 14 : 0 ) ; tmp_i = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_e + (
ssGetTaskTime ( rtS , 2 ) >= 156000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 156400.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 156800.0 ? 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 157200.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 157600.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 158000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158400.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158800.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 159200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 159600.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160400.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 160800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 161200.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 161600.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 162000.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 162400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 162800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 163200.0 ? 26
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 163600.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 164000.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 164400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164800.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 165200.0 ? 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 165600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 166000.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166400.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166800.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 167200.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 167600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168000.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168400.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 168800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 169200.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 169600.0 ? - 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 170000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 170400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 170800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171200.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171600.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 172000.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 172400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 172800.0 ? - 9 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 173200.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 173600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 174000.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174400.0 ? -
35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174800.0 ? 42 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 175200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
175600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176000.0 ? 31 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 176400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 176800.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
177200.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 177600.0 ? - 19 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 178000.0 ? - 30 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 178400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 178800.0
? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 179200.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 179600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 180000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180400.0 ? -
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 181200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 181600.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182000.0 ? 42
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182400.0 ? - 49 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 182800.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 183200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 183600.0 ? - 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 184000.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 184400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 184800.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185200.0 ? 21
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185600.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 186000.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 186400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 186800.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 187200.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 187600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 188000.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188400.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 189200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 189600.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190000.0 ? -
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190400.0 ? 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 190800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 191200.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 191600.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 192000.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 192400.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 192800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193200.0 ? -
34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 194000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 194400.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 194800.0 ? 13 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 195200.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 195600.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 196000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196400.0 ? - 35
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196800.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 197200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 197600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198000.0 ? - 29
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198800.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 199200.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 199600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200000.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200400.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 200800.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 201200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 201600.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 202000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 202400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 202800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 203200.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 203600.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 204000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 204800.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 205200.0 ? - 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 205600.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 206000.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 206400.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 206800.0 ? 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 207200.0 ? - 25 : 0 ) ; tmp_m = ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( tmp_i + ( ssGetTaskTime ( rtS , 2 ) >= 207600.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 208000.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 208400.0 ? 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 208800.0 ? -
30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 209200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 209600.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 210000.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210400.0 ? - 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210800.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 211200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 211600.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212000.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 212800.0 ? 39 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 213200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 213600.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 214000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 214400.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 214800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215200.0 ? - 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 216000.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 216400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216800.0 ? -
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 217200.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 217600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 218000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218400.0 ? - 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218800.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 219200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 219600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220000.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220400.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 220800.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 221200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 221600.0 ? - 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222000.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 222400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 222800.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 223200.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 223600.0 ? - 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 224000.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 224400.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224800.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 225200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 225600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 226000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 226800.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 227200.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 227600.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 228000.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228400.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228800.0 ? 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 229200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 229600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230000.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230400.0 ? 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 230800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
231200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 231600.0 ? - 24 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 232000.0 ? 6 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 232400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
232800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 233200.0 ? 24 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 233600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 234000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234400.0
? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 235200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 235600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236000.0 ? 32 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236400.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 236800.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 237200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 237600.0 ? -
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238000.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 238400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 238800.0 ? - 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239200.0 ? 31 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239600.0 ? 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 240000.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
240400.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 240800.0 ? - 21 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 241200.0 ? 38 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 241600.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
242000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 242400.0 ? - 13 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 242800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 243200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
243600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 244000.0 ? - 19 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 244400.0 ? 11 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 244800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 245200.0 ?
- 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 245600.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 246000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 246400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246800.0 ? - 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 247200.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 247600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 248000.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248400.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248800.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 249600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 250000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250400.0 ? - 25
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250800.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 251200.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 251600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252000.0 ?
15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252400.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 252800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 253200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 253600.0 ? - 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 254000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 254400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 254800.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255200.0 ? - 48
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255600.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 256000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 256400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 256800.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 257200.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 257600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 258000.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258400.0 ? 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258800.0 ? - 5 : 0 ) ; tmp_g = ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( tmp_m + ( ssGetTaskTime ( rtS , 2 ) >= 259200.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 259600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 260000.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260400.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260800.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 261200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 261600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262000.0 ? 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262400.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 262800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 263200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 263600.0 ? 10 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 264000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 264400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 264800.0
? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 265200.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 265600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 266000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266400.0 ? 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266800.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 267200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 267600.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268000.0 ? 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268400.0 ? - 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 268800.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 269200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 269600.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 270000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 270400.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 270800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271200.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271600.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 272000.0 ? - 46 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 272400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 272800.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 273200.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 273600.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 274000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274400.0 ? 28
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274800.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 275200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 275600.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276000.0 ? 38 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276400.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 276800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 277200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 277600.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 278000.0 ? - 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 278400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 278800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279200.0 ? 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279600.0 ? 24 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 280000.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
280400.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 280800.0 ? - 20 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 281200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 281600.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282000.0
? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 283200.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 283600.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284000.0 ? 34
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 284800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 285200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 285600.0 ? 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 286000.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 286400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 286800.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287200.0 ? -
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287600.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 288000.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 288400.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289200.0 ? - 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289600.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 290000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 290400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 290800.0 ? 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 291200.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 291600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 292000.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292400.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292800.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 293200.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 293600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294000.0 ?
41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294400.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 294800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 295200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 295600.0 ? -
1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 296000.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 296400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 296800.0 ? 50 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297200.0 ? - 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297600.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 298000.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 298400.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 298800.0 ? -
26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 299200.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 299600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 300000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300800.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 301200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 301600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302000.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302400.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 302800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 303200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 303600.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 304000.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 304400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 304800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305200.0 ?
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305600.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 306000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 306400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306800.0 ? 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 307200.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 307600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 308000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308400.0 ? - 37
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308800.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 309200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 309600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310000.0 ? 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310400.0 ? - 8 : 0 ) ; tmp_j = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( tmp_g + ( ssGetTaskTime ( rtS , 2 ) >= 310800.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 311200.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 311600.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 312000.0 ? -
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 312800.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 313200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 313600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314000.0 ? -
8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314400.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 314800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 315200.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 315600.0 ? 31 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316000.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 316400.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 316800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 317200.0 ? - 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 317600.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 318000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 318400.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318800.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 319200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 319600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320000.0
? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320400.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 320800.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 321200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 321600.0 ? -
21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 322000.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 322400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 322800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323200.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323600.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 324000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 324400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324800.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 325200.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 325600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 326000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326400.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 327200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 327600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328000.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328400.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 328800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 329200.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 329600.0 ?
24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 330000.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 330400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 330800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 331200.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 331600.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 332000.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 332400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332800.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 333200.0 ? 42 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 333600.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 334000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334400.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334800.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 335200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 335600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336000.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336400.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 336800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 337200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 337600.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338000.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 338400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 338800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 339200.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 339600.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 340000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 340400.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 340800.0 ? 15 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341200.0 ? - 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 341600.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 342000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342400.0 ? 22 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342800.0 ? - 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 343200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 343600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344000.0 ? 26 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344400.0 ? 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 344800.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
345200.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 345600.0 ? - 42 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 346000.0 ? 46 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 346400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
346800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 347200.0 ? 22 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 347600.0 ? - 18 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 348000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348400.0
? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348800.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 349200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 349600.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350000.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350400.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 350800.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 351200.0 ? - 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 351600.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352000.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 352400.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 352800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 353200.0 ? 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 353600.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 354000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 354400.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354800.0 ? -
38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 355200.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 355600.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 356000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356400.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 357200.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 357600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358000.0 ? 16 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358400.0 ? 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 358800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
359200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 359600.0 ? - 20 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 360000.0 ? - 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 360400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 360800.0 ?
- 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 361200.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 361600.0 ? - 7 : 0 ) ; rtB . c2nnsvritk = ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( real_T ) ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( tmp_j + ( ssGetTaskTime ( rtS , 2 ) >= 362000.0 ? 10 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 362400.0 ? 14 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 362800.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
363200.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 363600.0 ? 11 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 364000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 364400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 364800.0 ?
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 365200.0 ? - 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 365600.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 366000.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366400.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366800.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 367200.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 367600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368000.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368400.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 368800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 369200.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 369600.0 ? -
29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 370000.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 370400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 370800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371200.0 ? 2 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371600.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 372000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 372400.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372800.0 ? -
22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 373200.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 373600.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 374000.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374400.0 ? 4 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374800.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 375200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 375600.0 ? - 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 377200.0 ? 2.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 377600.0 ? 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378000.0
? 14.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378400.0 ? - 14.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 378800.0 ? - 25.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 379200.0 ? 42.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 379600.0 ? - 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
380000.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380400.0 ? 2.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380800.0 ? - 23.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 381200.0 ? 27.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 381600.0 ? - 26.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
382000.0 ? 9.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382400.0 ? 13.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382800.0 ? 4.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 383200.0 ? - 21.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 383600.0 ? 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
384000.0 ? - 19.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384400.0 ? - 9.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384800.0 ? 25.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 385200.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 385600.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
386000.0 ? 36.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386400.0 ? - 30.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386800.0 ? 11.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 387200.0 ? - 17.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 387600.0 ? 20.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
388000.0 ? - 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388400.0 ? - 4.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388800.0 ? - 1.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 389200.0 ? 18.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 389600.0 ? - 14.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
390000.0 ? - 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390400.0 ? 12.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390800.0 ? - 24.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 391200.0 ? 21.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 391600.0 ? 12.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
392000.0 ? - 30.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392400.0 ? 35.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392800.0 ? - 44.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 393200.0 ? 6.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 393600.0 ? 30.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394000.0
? 7.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394400.0 ? - 28.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 394800.0 ? - 10.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 395200.0 ? 6.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 395600.0 ? 10.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396000.0
? 16.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396400.0 ? - 16.0 : 0.0 ) ;
break ; default : tmp_m0 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ssGetTaskTime ( rtS , 2 ) >=
0.0 ? 40 : 0 ) + ( ssGetTaskTime ( rtS , 2 ) >= 400.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 800.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 1200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 1600.0 ? 8 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 2000.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 2400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2800.0 ? 25 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 3600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 4000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4400.0
? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4800.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 5200.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 5600.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6000.0 ? - 37 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 6400.0 ? 42 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 6800.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 7200.0 ?
- 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 7600.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 8000.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 8400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8800.0 ? 14 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 9200.0 ? - 39 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 9600.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10000.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 10400.0 ? - 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 10800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 11200.0
? 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 11600.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 12000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 12400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12800.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 13200.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 13600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 14000.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14400.0 ? 17 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 15200.0 ? 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 15600.0
? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 16000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 16400.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 16800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17200.0 ? - 23 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17600.0 ? 17 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 18000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
18400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18800.0 ? - 25 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 19200.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 19600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20000.0 ? 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20400.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 20800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 21200.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21600.0 ? - 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22000.0 ? 26 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 22400.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22800.0 ?
- 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 23600.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 24000.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 24400.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24800.0 ? 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25200.0 ? 13 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 25600.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
26000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26400.0 ? - 15 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 26800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 27200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 27600.0 ? 31 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28000.0 ? - 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 28400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 28800.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29200.0 ? 36 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29600.0 ? - 47 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 30000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 30400.0 ?
30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 30800.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 31200.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 31600.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32000.0 ? 8 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 32400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 32800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 33600.0
? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34000.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 34400.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 34800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 35200.0 ? 27 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 35600.0 ? - 14 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 36000.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
36400.0 ? 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 36800.0 ? - 22 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 37200.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 37600.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38000.0 ? - 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38400.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 38800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 39200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39600.0 ? 2 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 40000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 40400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 40800.0 ?
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 41600.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 42000.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 42400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42800.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 43200.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 43600.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 44000.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44400.0 ? 4 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44800.0 ? 10 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 45200.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 45600.0 ?
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 46000.0 ? - 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 46400.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
46800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 47200.0 ? - 7 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 47600.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 48000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48400.0 ? 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48800.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 49200.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 49600.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50000.0 ? - 14 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50400.0 ? 2 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 50800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
51200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 51600.0 ? 16 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 52000.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 52400.0 ? 10 : 0 ) ; tmp_fv = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_m0 + (
ssGetTaskTime ( rtS , 2 ) >= 52800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 53200.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 53600.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 54000.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 54400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 54800.0 ? - 40 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 55200.0 ? 6 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 55600.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56000.0
? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56400.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 56800.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 57200.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 57600.0 ? 32 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 58000.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 58400.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 58800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 59600.0 ? 8 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 60000.0 ? 6 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 60400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 60800.0 ?
- 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 61200.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 61600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 62000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62400.0 ? - 16 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62800.0 ? - 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 63200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 63600.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64000.0 ? 8 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 64400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 64800.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 65200.0 ?
9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 65600.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 66000.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 66400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66800.0 ? 3 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 67200.0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 67600.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68000.0 ? 38 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68400.0 ? - 33 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 68800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69200.0
? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69600.0 ? - 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 70000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 70400.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 70800.0 ? - 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71200.0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 71600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72000.0 ? 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72400.0 ? 20 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 72800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 73200.0 ?
- 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 73600.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 74000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 74400.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74800.0 ? 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75200.0 ? 12 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 75600.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76000.0
? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76400.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 76800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 77200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 77600.0 ? - 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78000.0 ? 29 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 78400.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78800.0 ? - 28 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 79200.0 ? 37 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 79600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 80000.0
? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 80400.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 80800.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 81200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 81600.0 ? - 33 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82000.0 ? 13 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 82400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
82800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 83200.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 83600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 84000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84400.0 ? - 17 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84800.0 ? - 16 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 85200.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 85600.0
? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 86000.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 86400.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 86800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 87600.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 88000.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88400.0 ? 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 89200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 89600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90000.0 ? 8 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 90800.0 ? - 27 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 91200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 91600.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 92400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 92800.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 93200.0 ? - 29 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 93600.0 ? - 12 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 94000.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94800.0
? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 95200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 95600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 96000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96400.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 96800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 97200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 97600.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98000.0 ? 31 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 98400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
98800.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 99200.0 ? - 7 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 99600.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 100000.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100400.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100800.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 101200.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 101600.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102000.0 ? 3
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102400.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 102800.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103200.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103600.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 104000.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 104400.0
? - 32 : 0 ) ; tmp_m4 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_fv + ( ssGetTaskTime ( rtS , 2
) >= 104800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 105200.0 ? - 26 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 105600.0 ? 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 106000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 106400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 106800.0 ? 11 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107200.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 107600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 108000.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 108400.0 ? - 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 108800.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 109200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 109600.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110400.0 ? 16 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110800.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 111200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 111600.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112000.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112400.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 112800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 113200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 113600.0 ? 16 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 114000.0 ? 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 114400.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 114800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115200.0 ? -
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115600.0 ? 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 116000.0 ? - 47 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 116400.0 ? 47 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 116800.0 ? -
33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 117200.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 117600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 118000.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118400.0 ? 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118800.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 119200.0 ? - 45 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 119600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120000.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120400.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 120800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 121200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 121600.0 ? -
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 122000.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 122400.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 122800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 123200.0 ? -
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 123600.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 124000.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 124400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 124800.0 ? 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 125200.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 125600.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 126000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126400.0 ? - 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126800.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 127200.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 127600.0 ? 49 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 128000.0 ? -
42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 128400.0 ? 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 128800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 129200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 129600.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 130000.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 130400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 130800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131200.0 ? 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131600.0 ? 6 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 132000.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132400.0
? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132800.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 133200.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 133600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134000.0 ? - 23
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134400.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 134800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 135200.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 135600.0 ? 19
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136000.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 136400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 136800.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137200.0 ? 14 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137600.0 ? 3 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 138000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
138400.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 138800.0 ? - 11 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 139200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 139600.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
140000.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140400.0 ? - 12 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 140800.0 ? 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 141200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 141600.0 ?
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 142000.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 142400.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 142800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143200.0 ? 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143600.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 144000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 144400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 144800.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145200.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 145600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 146000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 146400.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 146800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 147200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 147600.0 ?
22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148000.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 148400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 148800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 149200.0 ? -
16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 149600.0 ? 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 150000.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 150400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150800.0 ? -
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 151200.0 ? 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 151600.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 152000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152400.0 ?
30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152800.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 153200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 153600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154000.0 ? -
29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154400.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 154800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 155200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 155600.0 ?
33 : 0 ) ; tmp_nf = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_m4 + ( ssGetTaskTime ( rtS , 2 ) >=
156000.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 156400.0 ? - 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 156800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 157200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
157600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158000.0 ? 15 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 158400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 158800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 159200.0 ? -
16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 159600.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 160000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 160400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160800.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 161200.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 161600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 162000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 162400.0 ? 26
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 162800.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 163200.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 163600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164000.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 164800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 165200.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 165600.0 ? 31 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166000.0 ? 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 166400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166800.0
? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 167200.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 167600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 168000.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168400.0 ? - 1 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168800.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 169200.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 169600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 170000.0 ? - 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 170400.0 ? 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 170800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 171200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171600.0 ? - 41
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 172000.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 172400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 172800.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 173200.0 ? 16 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 173600.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 174000.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 174400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174800.0 ? -
13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 175200.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 175600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176000.0
? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176400.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 176800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 177200.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 177600.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 178000.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 178400.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 178800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 179200.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 179600.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 180000.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 180400.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180800.0 ? 19
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 181200.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 181600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 182000.0 ? - 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182400.0 ? 35
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182800.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 183200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 183600.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 184000.0 ? 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 184400.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 184800.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 185200.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185600.0 ? 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 186000.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 186400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 186800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 187200.0 ? - 10 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 187600.0 ? 14 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 188000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
188400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188800.0 ? 13 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 189200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 189600.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190000.0
? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190400.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 190800.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 191200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 191600.0 ?
40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 192000.0 ? - 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 192400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 192800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193200.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193600.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 194000.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 194400.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 194800.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 195200.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 195600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 196000.0 ? 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196400.0 ? -
6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196800.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 197200.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 197600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198000.0 ? 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198400.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 198800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 199200.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 199600.0 ? -
26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200000.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 200400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 200800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 201200.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 201600.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 202000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
202400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 202800.0 ? - 1 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 203200.0 ? 4 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 203600.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 204000.0
? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 204400.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 204800.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 205200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 205600.0 ?
33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 206000.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 206400.0 ? - 6 : 0 ) ; tmp_mi = ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( tmp_nf + ( ssGetTaskTime ( rtS , 2 ) >= 206800.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 207200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 207600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 208000.0 ? -
21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 208400.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 208800.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 209200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 209600.0 ? - 37
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210000.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 210400.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 210800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 211200.0 ? -
6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 211600.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 212000.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 212400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212800.0 ? - 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 213200.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 213600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 214000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 214400.0 ? - 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 214800.0 ? - 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 215200.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 215600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216000.0 ? -
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216400.0 ? 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 216800.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 217200.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 217600.0 ? 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218000.0 ? - 44 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 218400.0 ? 44 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 218800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 219200.0 ? -
13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 219600.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 220000.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 220400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220800.0 ? - 37
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 221200.0 ? 32 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 221600.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 222000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222400.0 ?
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222800.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 223200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 223600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224000.0 ? - 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224400.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 224800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 225200.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 225600.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 226000.0 ? - 4 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 226400.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 226800.0
? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 227200.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 227600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 228000.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228400.0 ? 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228800.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 229200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 229600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230000.0 ? 29
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230400.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 230800.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 231200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 231600.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 232000.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 232400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 232800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 233200.0 ? - 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 233600.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 234000.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 234400.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234800.0 ? - 20
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 235200.0 ? 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 235600.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 236000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236400.0 ? 18
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236800.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 237200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 237600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238000.0 ?
38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238400.0 ? - 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 238800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 239200.0 ? 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239600.0 ? - 47 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 240000.0 ? 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 240400.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 240800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 241200.0 ?
46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 241600.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 242000.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 242400.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 243200.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 243600.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 244000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 244400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 244800.0 ? 43
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 245200.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 245600.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 246000.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246400.0 ? 2 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246800.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 247200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 247600.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248000.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248400.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 248800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 249200.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 249600.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 250000.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 250400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250800.0 ? -
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 251200.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 251600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 252000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252400.0 ? 26
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252800.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 253200.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 253600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 254000.0 ? 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 254400.0 ? - 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 254800.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 255200.0 ? 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255600.0 ? - 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 256000.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 256800.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 257200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 257600.0 ? - 33 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258000.0 ? 13 : 0 ) ; tmp_b0 = ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( tmp_mi + ( ssGetTaskTime ( rtS , 2 ) >= 258400.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 258800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 259200.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 259600.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260000.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 260400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 260800.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 261200.0 ? - 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 261600.0 ? 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 262000.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 262400.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262800.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 263200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
263600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 264000.0 ? 36 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 264400.0 ? - 15 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 264800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
265200.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 265600.0 ? - 15 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 266000.0 ? 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 266400.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266800.0
? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 267200.0 ? - 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 268400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 268800.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 269200.0 ? 18 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 269600.0 ? - 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 270000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 270400.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 270800.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271200.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 271600.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 272000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 272400.0 ?
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 272800.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 273200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 273600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274400.0 ? -
16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274800.0 ? 44 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 275200.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 275600.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276000.0 ? -
6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276400.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 276800.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 277200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 278000.0 ? - 28 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 278400.0 ? 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 278800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
279200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279600.0 ? 10 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 280000.0 ? - 23 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 280400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
280800.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 281200.0 ? 7 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 281600.0 ? - 14 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 282000.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282400.0
? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282800.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 283200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 283600.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284000.0 ? -
17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284400.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 284800.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 285200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 286000.0 ? - 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 286400.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 286800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 287200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287600.0 ? - 1 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 288000.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 288400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 288800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289200.0 ? 20
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289600.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 290000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 290400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 290800.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 291200.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 292000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 292400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292800.0 ? 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 293200.0 ? 3 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 293600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294000.0
? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294400.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 294800.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 295200.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 295600.0 ? 34
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 296000.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 296400.0 ? - 41 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 296800.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297200.0 ? -
35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297600.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 298000.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 298400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 298800.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 299200.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 299600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 300000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300400.0 ? 23
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300800.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 301200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 302000.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302400.0 ? - 24 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302800.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 303200.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 303600.0 ? 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 304000.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 304400.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 304800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 305200.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305600.0 ? - 26
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306000.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 306400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306800.0 ?
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 307200.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 307600.0 ? - 49 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 308000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308400.0 ? -
36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308800.0 ? 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 309200.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 309600.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310000.0 ? -
1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310400.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 310800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 311200.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 311600.0 ? 14
: 0 ) ; tmp_cc = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_b0 + ( ssGetTaskTime ( rtS , 2 ) >=
312000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 312400.0 ? - 8 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 312800.0 ? 15 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 313200.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 313600.0
? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314000.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 314400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 314800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 315200.0 ?
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 315600.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 316000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 316400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316800.0 ? - 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 317200.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 317600.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 318000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318400.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 319200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 319600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320000.0 ? 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320400.0 ? - 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 320800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 321600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 322000.0 ? - 20 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 322400.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 322800.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 323200.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323600.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324000.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 324400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 324800.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 325200.0 ? 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 325600.0 ? - 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 326000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 326400.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326800.0 ? 15 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 327200.0 ? - 48 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 327600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 328000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328400.0 ? - 38
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328800.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 329200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 329600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 330000.0 ? 22 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 330400.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 330800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 331200.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 331600.0 ? 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332000.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 332400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 332800.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 333200.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 333600.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 334000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 334400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334800.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 335200.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 335600.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 336000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336400.0 ? 15 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336800.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 337200.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 337600.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338000.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338400.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 338800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 339200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 339600.0 ? - 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 340000.0 ? - 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 340400.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 340800.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341200.0 ? 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341600.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 342000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 342400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342800.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 343200.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 343600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 344000.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344400.0 ? - 39 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344800.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 345200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
345600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 346000.0 ? 47 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 346400.0 ? - 39 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 346800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 347200.0
? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 347600.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 348000.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 348400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348800.0 ? -
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 349200.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 349600.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 350000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350400.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350800.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 351200.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 351600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352000.0 ?
39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352400.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 352800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 353200.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 353600.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 354000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 354400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354800.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 355200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 355600.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 356000.0 ? 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356400.0 ? - 46
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356800.0 ? 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 357200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 357600.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358000.0 ?
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358400.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 358800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 359200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 359600.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 360000.0 ? - 45 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 360400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 360800.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 361200.0 ? - 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 361600.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 362000.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 362400.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 362800.0 ? 12
: 0 ) ; rtB . c2nnsvritk = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( real_T ) ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_cc + ( ssGetTaskTime (
rtS , 2 ) >= 363200.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 363600.0
? - 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 364000.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 364400.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 364800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 365200.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 365600.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 366000.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 366400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366800.0 ? - 18
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 367200.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 367600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 368000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368400.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368800.0 ? 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 369200.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 369600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 370000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 370400.0 ? - 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 370800.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 371200.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371600.0 ? - 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372000.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 372400.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 372800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 373200.0 ? - 36 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 373600.0 ? 3 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 374000.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374400.0
? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374800.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 375200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 375600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376000.0 ?
48 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376400.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 376800.0 ? 8.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 377200.0 ? - 3.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378000.0
? - 26.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378400.0 ? 26.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 378800.0 ? - 14.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 379200.0 ? - 10.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 379600.0 ? - 15.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
380000.0 ? 31.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380400.0 ? - 5.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380800.0 ? - 22.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 381200.0 ? 24.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 381600.0 ? - 17.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
382000.0 ? - 1.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382400.0 ? - 8.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382800.0 ? 22.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 383200.0 ? 8.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 383600.0 ? 17.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384000.0
? - 15.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384400.0 ? 13.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 384800.0 ? - 40.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 385200.0 ? 26.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 385600.0 ? 5.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
386000.0 ? - 33.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386400.0 ? - 5.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386800.0 ? 5.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 387200.0 ? 40.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 387600.0 ? - 44.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
388000.0 ? 47.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388400.0 ? - 48.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388800.0 ? 21.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 389200.0 ? 20.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 389600.0 ? - 38.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
390000.0 ? 2.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390400.0 ? 35.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390800.0 ? - 32.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 391200.0 ? 5.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 391600.0 ? 26.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392000.0
? - 26.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392400.0 ? 16.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 392800.0 ? - 2.0 : 0.0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 393200.0 ? - 15.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
393600.0 ? 25.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394000.0 ? - 36.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394400.0 ? 21.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 394800.0 ? 22.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 395200.0 ? - 34.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
395600.0 ? 31.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396000.0 ? - 30.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396400.0 ? - 6.0 : 0.0 ) ; break ;
} switch ( ( int32_T ) rtP . WaveformGenerator_SelectedSignal ) { case 1 :
tmp_o = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ssGetTaskTime ( rtS , 2 ) >= 0.0 ? 40 : 0 ) + (
ssGetTaskTime ( rtS , 2 ) >= 400.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 1200.0 ? - 21 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 1600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 2000.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2400.0 ? 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2800.0 ? 4 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 3200.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 3600.0
? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4000.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 4800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 5200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 5600.0 ? - 19 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6000.0 ? 22 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 6400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6800.0 ?
26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 7200.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 7600.0 ? - 35 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 8000.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8400.0 ? - 24 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 9200.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 9600.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10000.0 ?
- 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10400.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 10800.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 11200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 11600.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12000.0 ? 4 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 12400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12800.0 ?
- 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 13200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 13600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 14000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14400.0 ? 24 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14800.0 ? - 13 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 15200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 15600.0 ?
- 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 16000.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 16400.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 16800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17200.0 ? - 19 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 18000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18400.0 ?
34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18800.0 ? - 47 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 19200.0 ? 47 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 19600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20000.0 ? 5 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20400.0 ? 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 20800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21200.0 ?
- 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21600.0 ? 42 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 22000.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 22400.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22800.0 ? 17 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 23200.0 ? - 18 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 23600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24000.0
? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24400.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 24800.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 25200.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25600.0 ? - 15 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26000.0 ? 21 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 26400.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26800.0
? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 27200.0 ? - 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 27600.0 ? 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 28000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28400.0 ? - 42 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28800.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 29200.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29600.0 ?
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 30000.0 ? - 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 30400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 30800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 31200.0 ? 9 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 31600.0 ? - 24 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 32000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32400.0 ?
- 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32800.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 33200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 33600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34000.0 ? - 33 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34400.0 ? 36 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 34800.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 35200.0
? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 35600.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 36000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
36400.0 ? 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 36800.0 ? - 23 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 37200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 37600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38000.0 ? 7 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38400.0 ? - 18 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 38800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39200.0
? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39600.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 40000.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 40400.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 40800.0 ? - 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 41200.0 ? 10 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 41600.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
42000.0 ? 49 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42400.0 ? - 36 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 42800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 43200.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 43600.0 ? 38
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44000.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 44400.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 44800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 45200.0 ? - 12 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 46000.0 ? 19 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 46400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
46800.0 ? 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 47200.0 ? - 46 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 47600.0 ? 50 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 48000.0 ? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48400.0 ? 28
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48800.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 49200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 49600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50000.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50400.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 50800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 51200.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 51600.0 ? 2 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 52000.0 ? 19 : 0 ) ; tmp_dz = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( tmp_o + ( ssGetTaskTime ( rtS , 2 ) >= 52400.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 52800.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 53200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 53600.0 ? 10 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 54000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 54400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 54800.0
? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 55200.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 55600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 56000.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56400.0 ? - 29 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56800.0 ? 28 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 57200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 57600.0
? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 58000.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 58400.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
58800.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 59200.0 ? - 9 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 59600.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 60000.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 60400.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 60800.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 61200.0 ? 48 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 61600.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62400.0 ? 29 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62800.0 ? 10 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 63200.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 63600.0
? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64000.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 64400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 64800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 65200.0 ? - 39 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 65600.0 ? 5 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 66000.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66400.0
? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66800.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 67200.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 67600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68000.0 ? 47 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68400.0 ? - 32 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 68800.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 69200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69600.0 ? - 16 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 70000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 70800.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71200.0
? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71600.0 ? - 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 72000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 72400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72800.0 ? 28 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 73200.0 ? - 34 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 73600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74000.0 ?
38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74400.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 74800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 75200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75600.0 ? - 32 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76000.0 ? 36 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 76400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76800.0
? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 77200.0 ? 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 77600.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 78000.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78400.0 ? - 18 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78800.0 ? 12 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 79200.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
79600.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 80000.0 ? - 19 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 80400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 80800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 81200.0 ? 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 81600.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 82000.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 82400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82800.0 ? 11 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 83200.0 ? 7 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 83600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84000.0 ?
19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84400.0 ? - 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 84800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 85200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 85600.0 ? - 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 86000.0 ? 28 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 86400.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
86800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87200.0 ? 11 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 87600.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
88000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88400.0 ? - 10 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 88800.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 89600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90000.0 ? -
24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90400.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 90800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 91200.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 91600.0 ? - 45 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92000.0 ? 22 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 92400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92800.0 ?
- 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 93200.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 93600.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 94000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94400.0 ? 14 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94800.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 95200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 95600.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96000.0 ? 19 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 96800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 97200.0
? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 97600.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 98000.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 98400.0 ? - 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98800.0 ? - 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 99200.0 ? 45 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 99600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
100000.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100400.0 ? - 36 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 100800.0 ? 17 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 101200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
101600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102000.0 ? 30 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 102400.0 ? 11 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 102800.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
103200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 103600.0 ? 13 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 104000.0 ? - 14 : 0 ) ; tmp_fs = ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( tmp_dz + ( ssGetTaskTime ( rtS , 2 ) >= 104400.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 104800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 105200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 105600.0 ? -
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 106000.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 106400.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 106800.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107200.0 ?
30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107600.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 108000.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 108400.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 108800.0 ? 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 109200.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 109600.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 110000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110400.0 ? - 21 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 110800.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 111200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 111600.0 ?
34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112000.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 112400.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 112800.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 113200.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 113600.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 114000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 114400.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 114800.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115200.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 115600.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 116000.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 116400.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 116800.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 117200.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 117600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118000.0 ? - 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118400.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 118800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 119200.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 119600.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120000.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 120400.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 120800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 121200.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 121600.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 122000.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 122400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 122800.0 ? 19
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 123200.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 123600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 124000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 124800.0 ? -
45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 125200.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 125600.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
126000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126400.0 ? - 42 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 126800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 127200.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 127600.0
? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 128000.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 128400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 128800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 129200.0 ? 19
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 129600.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 130000.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 130400.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 130800.0 ? -
13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131200.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 131600.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 132000.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132400.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132800.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 133200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 133600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134000.0 ? - 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134400.0 ? 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 134800.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 135200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 135600.0 ?
33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136000.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 136400.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 136800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137200.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137600.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 138000.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 138400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 138800.0 ?
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 139200.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 139600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 140000.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140400.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140800.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 141200.0 ? - 48 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 141600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 142000.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 142400.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 142800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 143200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143600.0 ? 2 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 144000.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 144400.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 144800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145600.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 146000.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 146400.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 146800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 147200.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 147600.0 ? 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 148000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 148400.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148800.0 ? - 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 149200.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 149600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 150000.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150400.0 ? 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150800.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 151200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 151600.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152000.0 ? -
13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152400.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 152800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 153200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 153600.0 ? 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154000.0 ? 2 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 154400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154800.0 ?
6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 155200.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 155600.0 ? - 11 : 0 ) ; tmp_ck = ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( tmp_fs + ( ssGetTaskTime ( rtS , 2 ) >= 156000.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 156400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 156800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 157200.0 ? 20
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 157600.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 158000.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 158400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158800.0 ? 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 159200.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 159600.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 160000.0 ? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160400.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160800.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 161200.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 161600.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 162000.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 162400.0 ? 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 162800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 163600.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164000.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164400.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 164800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 165200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 165600.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166400.0 ? - 49 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 166800.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 167200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 167600.0 ? - 11 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168000.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 168400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 168800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 169200.0 ?
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 170000.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 170400.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 170800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171200.0 ?
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171600.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 172000.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 172400.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 172800.0 ? 21
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 173200.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 173600.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 174000.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174400.0 ?
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174800.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 175200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 175600.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176000.0 ? -
44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176400.0 ? 47 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 176800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 177200.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 177600.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 178000.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 178400.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 178800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 179200.0 ? 25
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 179600.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 180000.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 180400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180800.0 ? 7 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 181200.0 ? 12 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 181600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
182000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182400.0 ? - 26 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 182800.0 ? 24 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 183200.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
183600.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 184000.0 ? 13 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 184400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 184800.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
185200.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185600.0 ? - 35 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 186000.0 ? 40 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 186400.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
186800.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 187200.0 ? 17 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 187600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 188000.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188400.0
? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188800.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 189200.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 189600.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190000.0 ? -
43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190400.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 190800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 191200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 191600.0 ? - 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 192000.0 ? - 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 192400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 192800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193200.0 ? - 12 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193600.0 ? 32 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 194000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 194400.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 194800.0 ? 18 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 195200.0 ? - 31 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 195600.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196000.0
? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196400.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 196800.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 197200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 197600.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198000.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 198400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 198800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 199200.0 ? -
15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 199600.0 ? 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 200000.0 ? - 41 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 200400.0 ? 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200800.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 201200.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 201600.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 202000.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 202400.0 ? -
21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 202800.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 203200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 203600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 204000.0 ? -
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 204400.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 204800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 205200.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 205600.0 ? 7 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 206000.0 ? 18 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 206400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
206800.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 207200.0 ? - 10 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 207600.0 ? 18 : 0 ) ; tmp_f2 = ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( tmp_ck + ( ssGetTaskTime ( rtS , 2 ) >= 208000.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 208400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 208800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 209200.0 ? -
4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 209600.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 210000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
210400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210800.0 ? - 17 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 211200.0 ? 6 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 211600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212000.0
? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212400.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 212800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 213200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 213600.0 ? 17 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 214000.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 214400.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 214800.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215200.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215600.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 216000.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 216400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216800.0 ? 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 217200.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 217600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 218000.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218400.0 ? - 36
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218800.0 ? 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 219200.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 219600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220000.0 ? -
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220400.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 220800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 221200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 221600.0 ? -
15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222000.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 222400.0 ? 50 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 222800.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 223200.0 ? 3
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 223600.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 224000.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 224400.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224800.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 225200.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 225600.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 226000.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 226400.0 ? - 41
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 226800.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 227200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 227600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228400.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 228800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 229200.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 229600.0 ? - 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230000.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 230400.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 230800.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 231200.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 231600.0 ? - 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 232000.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 232400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 232800.0 ? - 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 233200.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 233600.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 234000.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234400.0 ? 29
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234800.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 235200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 235600.0 ? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236000.0 ? 31
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236400.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 236800.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 237200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 237600.0 ? 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 238400.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 238800.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239200.0 ? - 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 239600.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 240000.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 240400.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 240800.0 ? -
27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 241200.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 241600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 242000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 242400.0 ? - 28
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 242800.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 243200.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 243600.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 244000.0 ? -
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 244400.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 244800.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 245200.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 245600.0 ? -
39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246000.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 246400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 246800.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 247200.0 ? - 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 247600.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 248000.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 248400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248800.0 ? 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 249200.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 249600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 250000.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250400.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250800.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 251200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 251600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252000.0 ?
8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252400.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 252800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 253200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 253600.0 ? 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 254000.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 254400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 254800.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255600.0 ? 21
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 256000.0 ? - 32 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 256400.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 256800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 257200.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 257600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 258000.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258400.0 ? 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258800.0 ? 6 : 0 ) ; tmp_kt = ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( tmp_f2 + ( ssGetTaskTime ( rtS , 2 ) >= 259200.0 ? - 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 259600.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 260000.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260400.0 ? - 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260800.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 261200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 261600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262000.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 262400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 263200.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 263600.0
? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 264000.0 ? 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 264400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 264800.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 265200.0 ? - 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 265600.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 266000.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 266400.0 ? - 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266800.0 ? 29
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 267200.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 267600.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 268000.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268400.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268800.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 269200.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 269600.0 ?
- 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 270000.0 ? 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 270400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 270800.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271200.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271600.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 272000.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 272400.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 272800.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 273200.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 273600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 274000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274400.0 ? 47 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274800.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 275200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 275600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276000.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276400.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 276800.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 277200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 277600.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 278000.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 278400.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 278800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279200.0 ? -
22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279600.0 ? 26 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 280000.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 280400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 280800.0 ? 18
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 281200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 281600.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 282000.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282400.0 ? - 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282800.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 283200.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 283600.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284000.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284400.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 284800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
285200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 285600.0 ? - 24 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 286000.0 ? 46 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 286400.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
286800.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287200.0 ? 16 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 287600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 288000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 288400.0 ? - 39 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 288800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 289200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289600.0
? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 290000.0 ? 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 290400.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 290800.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 291200.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 291600.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 292000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 292400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292800.0 ? 9 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 293200.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 293600.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 294000.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294400.0 ? 23
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294800.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 295200.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 295600.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 296000.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 296400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 296800.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 297200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297600.0 ? - 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 298000.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 298400.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 298800.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 299200.0 ? - 9 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300000.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 300400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 300800.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 301200.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 301600.0 ? - 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 302400.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 302800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 303200.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 303600.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 304000.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 304400.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 304800.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305200.0 ? - 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 305600.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 306000.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306800.0 ? - 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 307200.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 307600.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308000.0 ? - 20
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 308800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 309200.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 309600.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310000.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 310400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 310800.0 ? - 3 : 0 ) ; tmp_lt = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_kt + (
ssGetTaskTime ( rtS , 2 ) >= 311200.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 311600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 312000.0 ? 4 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 312400.0 ? 12 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 312800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 313200.0
? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 313600.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 314000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 314400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314800.0 ? 36 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 315200.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 315600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 316000.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316400.0 ? 33 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316800.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 317200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 317600.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318000.0 ? 25
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318400.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 318800.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 319200.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 319600.0 ? 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320000.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 320400.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 320800.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 321200.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 321600.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 322000.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 322400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 322800.0 ? -
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323200.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 323600.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 324000.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324400.0 ? - 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324800.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 325200.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 325600.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326000.0 ? 41
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326400.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 326800.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 327200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 327600.0 ?
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328000.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 328400.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 328800.0 ? - 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 329200.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 329600.0 ? - 19 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 330000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 330400.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 330800.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 331200.0 ? 32 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 331600.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332000.0 ? - 3
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332400.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 332800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 333200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 333600.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334000.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 334400.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 334800.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 335200.0 ? -
35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 335600.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 336000.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 336400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336800.0 ?
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 337200.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 337600.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 338000.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338400.0 ? 17 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338800.0 ? - 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 339200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 339600.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 340000.0 ? - 21
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 340400.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 340800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 341200.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341600.0 ?
28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342000.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 342400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 342800.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 343200.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 343600.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 344000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 344400.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344800.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 345200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 345600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 346000.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 346400.0 ? - 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 346800.0 ? 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 347200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 347600.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348000.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 348400.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 348800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 349200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 349600.0 ? - 43
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350000.0 ? 42 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 350400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 350800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 351200.0 ? -
24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 351600.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 352000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 352400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352800.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 353200.0 ? - 44 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 353600.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 354000.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354400.0 ? - 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354800.0 ? 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 355200.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 355600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356000.0 ? 19
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356400.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 356800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 357200.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 357600.0 ? 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358000.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 358400.0 ? - 29 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 358800.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 359200.0 ? 20
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 359600.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 360000.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 360400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 360800.0 ? - 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 361200.0 ? 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 361600.0 ) ; bkywyomtj0 = ( ( real_T ) ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( tmp_lt + ( ssGetTaskTime ( rtS , 2 ) >= 362000.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 362400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 362800.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 363200.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 363600.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 364000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 364400.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 364800.0 ? - 9 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 365200.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 365600.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366000.0 ? -
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366400.0 ? 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 366800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 367200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 367600.0 ? -
34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368000.0 ? 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 368400.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 368800.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 369200.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 369600.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 370000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 370400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 370800.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371200.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 371600.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 372000.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372400.0 ? - 1
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372800.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 373200.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 373600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374000.0 ?
46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374400.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 374800.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 375200.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 375600.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376000.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 376400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 376800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 377200.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 377600.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 378000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 378400.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 378800.0 ? 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 379200.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 379600.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 380000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380400.0 ? - 36 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 380800.0 ? 9 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 381200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
381600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 382000.0 ? 7 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 382400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 382800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 383200.0 ?
26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 383600.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 384000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 384400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 384800.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 385200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 385600.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386000.0
? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386400.0 ? 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 386800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 387200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388000.0 ?
- 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388400.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 388800.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 389200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 389600.0 ? -
16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390000.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 390400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 390800.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 391200.0 ? - 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 391600.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 392000.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 392400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392800.0 ? 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 393200.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 393600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 394000.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394400.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 394800.0 ? - 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 395200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 395600.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396000.0 ? - 15.0 : 0.0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396400.0 ? 27.0 : 0.0 ) ; break ; case 2
: bkywyomtj0 = 25.0 ; break ; case 3 : bkywyomtj0 = ( ( ( ssGetTaskTime ( rtS
, 2 ) >= 36000.0 ? 0.5 : 0.0 ) + ( ssGetTaskTime ( rtS , 2 ) >= 57600.0 ? 0.5
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64800.0 ? 0.5 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 72000.0 ? 0.5 : 0.0 ) ; break ; case 4 : tmp_f =
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ssGetTaskTime ( rtS , 2 ) >= 0.0 ? 40 : 0 ) + (
ssGetTaskTime ( rtS , 2 ) >= 400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 1200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 1600.0 ? 3 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 2000.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 2400.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 2800.0 ? - 23 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 3200.0 ? 36 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 3600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4000.0 ?
- 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 4400.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 4800.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 5200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 5600.0 ? 14 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 6000.0 ? - 29 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 6400.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 6800.0 ? -
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 7200.0 ? 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 7600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 8000.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8400.0 ? - 26 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 8800.0 ? 5 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 9200.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 9600.0 ?
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 10000.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 10400.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
10800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 11200.0 ? 8 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 12000.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 12400.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 12800.0 ? 28 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 13200.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 13600.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 14000.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14400.0 ? 19 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 14800.0 ? 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 15200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 15600.0 ?
- 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 16000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 16400.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 16800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17200.0 ? 3 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 17600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 18000.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18400.0
? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 18800.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 19200.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 19600.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20000.0 ? - 3 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 20400.0 ? - 12 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 20800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21200.0
? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 21600.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 22000.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 22400.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 22800.0 ? - 37 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 23200.0 ? 11 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 23600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24000.0 ?
- 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 24400.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 24800.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 25200.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 25600.0 ? - 13 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 26400.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 26800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
27200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 27600.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 28000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 28400.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 28800.0 ? 10 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 29200.0 ? - 6 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 29600.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
30000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 30400.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 30800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 31200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 31600.0 ? - 7 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 32400.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 32800.0
? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 33200.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 33600.0 ? 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 34000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34400.0 ? - 2 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 34800.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 35200.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 35600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 36000.0 ? 2 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 36400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 36800.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
37200.0 ? 41 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 37600.0 ? - 21 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 38000.0 ? - 12 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 38400.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 38800.0 ?
- 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 39200.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 40000.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 40400.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 40800.0 ? - 4 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 41200.0 ? - 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 41600.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 42000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42400.0 ? 9 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 42800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 43200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 43600.0
? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 44000.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 44400.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 44800.0 ? - 47 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 45200.0 ? 32 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 45600.0 ? - 28 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 46000.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 46400.0
? 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 46800.0 ? - 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 47200.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 47600.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48000.0 ? 38 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 48400.0 ? - 29 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 49200.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 49600.0
? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 50000.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 50400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 50800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 51200.0 ? - 12 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 51600.0 ? 10 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 52000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 52400.0
? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 52800.0 ? - 21 : 0 ) ; tmp_c =
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( tmp_f + ( ssGetTaskTime ( rtS , 2 ) >= 53600.0 ? 36 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 54000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 54400.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 54800.0
? 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 55200.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 55600.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 56000.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56400.0 ? 18 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 56800.0 ? - 23 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 57200.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
57600.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 58000.0 ? - 38 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 58400.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 58800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 59200.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 59600.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 60000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 60400.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 60800.0 ? 5 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 61200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 61600.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62000.0
? - 42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 62400.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 62800.0 ? 46 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 63200.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 63600.0 ? - 9 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 64000.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 64400.0 ? 47 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 64800.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 65200.0 ? - 12 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 65600.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 66000.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 66400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 66800.0 ? - 24 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 67200.0 ? 31 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 67600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
68000.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 68400.0 ? - 16 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 68800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 69200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 69600.0 ?
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 70000.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 70400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 70800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71200.0 ? - 31 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 71600.0 ? 29 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 72000.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72400.0
? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 72800.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 73200.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 73600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74000.0 ? - 20 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 74400.0 ? 25 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 74800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75200.0
? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 75600.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 76000.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 76400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 76800.0 ? - 29 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 77200.0 ? 15 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 77600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78000.0 ?
22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 78400.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 78800.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 79200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 79600.0 ? - 5 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 80000.0 ? 4 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 80400.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 80800.0
? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 81200.0 ? 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 81600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 82000.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 82400.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 82800.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 83200.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 83600.0 ? 5 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84000.0 ? - 25 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 84400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 84800.0
? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 85200.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 85600.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 86000.0 ? - 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 86400.0 ? 34 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 86800.0 ? - 22 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 87200.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 87600.0
? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 88000.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 88400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 88800.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 89200.0 ? - 27 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 89600.0 ? - 18 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 90000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90400.0
? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 90800.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 91200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 91600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92000.0 ? - 17 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 92400.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 92800.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 93200.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 93600.0 ? - 24 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94000.0 ? 31 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 94400.0 ? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 94800.0
? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 95200.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 95600.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 96000.0 ? 49 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96400.0 ? - 44 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 96800.0 ? 25 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 97200.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 97600.0
? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 98000.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 98400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 98800.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 99200.0 ? - 9 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 99600.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 100000.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 100400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 100800.0 ? -
16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 101200.0 ? 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 101600.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 102000.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102400.0 ? 13
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 102800.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 103200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 103600.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 104000.0 ? 16
: 0 ) ; tmp_k = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_c + ( ssGetTaskTime ( rtS , 2 ) >=
104400.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 104800.0 ? - 5 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 105200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 105600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 106000.0 ?
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 106400.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 106800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 107200.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 107600.0 ? - 44 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 108000.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 108400.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 108800.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 109200.0 ? 12
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 109600.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 110000.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 110400.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 110800.0 ? - 48 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 111200.0 ? 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 111600.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 112000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112400.0 ?
14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 112800.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 113200.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 113600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 114000.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 114400.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 114800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 115200.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 115600.0 ?
40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 116000.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 116400.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 116800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 117200.0 ? - 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 117600.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 118000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
118400.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 118800.0 ? 46 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 119200.0 ? - 48 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 119600.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
120000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 120400.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 120800.0 ? 44 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 121200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 121600.0 ? - 3 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 122000.0 ? - 13 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 122400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 122800.0 ?
- 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 123200.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 123600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 124000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 124400.0 ? 32
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 124800.0 ? - 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 125200.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 125600.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126000.0 ? 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 126400.0 ? - 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 126800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 127200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 127600.0 ? 34
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 128000.0 ? - 39 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 128800.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 129200.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 129600.0 ? - 32 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 130000.0 ? 30 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 130400.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 130800.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131200.0 ?
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 131600.0 ? 15 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 132000.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 132400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 132800.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 133200.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 133600.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 134000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134400.0 ? - 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 134800.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 135200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 135600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136000.0 ? - 6 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 136400.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 136800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 137200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 137600.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 138000.0 ? 29 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 138400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
138800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 139200.0 ? - 46 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 139600.0 ? 27 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 140000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140400.0 ? 21 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 140800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 141200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
141600.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 142000.0 ? - 5 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 142400.0 ? - 38 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 142800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143200.0
? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 143600.0 ? - 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 144000.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 144400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 144800.0 ? 41
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 145200.0 ? - 32 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 145600.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 146000.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 146400.0 ? 22 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 146800.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 147200.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 147600.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 148000.0 ? - 14 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 148400.0 ? - 30 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 148800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 149200.0
? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 149600.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 150000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 150400.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 150800.0 ? 10 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 151200.0 ? - 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 151600.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 152000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152400.0 ?
29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 152800.0 ? - 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 153200.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 154000.0 ? - 43 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154400.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 154800.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 155200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 155600.0 ? 9 : 0 ) ; tmp_b = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_k + ( ssGetTaskTime
( rtS , 2 ) >= 156000.0 ? - 21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
156400.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 156800.0 ? 7 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 157200.0 ? 25 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 157600.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158000.0
? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 158400.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 158800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 159200.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 159600.0 ? - 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 160000.0 ? 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 160400.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 160800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 161200.0 ?
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 161600.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 162000.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 162800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 163200.0 ? -
13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 163600.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 164000.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 164400.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 164800.0 ? 16
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 165200.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 165600.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 166000.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166400.0 ? -
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 166800.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 167200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 167600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168000.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 168400.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 168800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 169200.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 169600.0 ? - 28
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 170000.0 ? 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 170400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 170800.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171200.0 ? - 22
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 171600.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 172000.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 172400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 172800.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 173200.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 173600.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174000.0 ? - 41 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 174400.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 174800.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 175200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 175600.0 ? -
9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 176000.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 176400.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 176800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 177200.0 ? -
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 177600.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 178000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
178400.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 178800.0 ? 26 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 179200.0 ? - 41 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 179600.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180000.0
? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 180400.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 180800.0 ? - 24 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 181200.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 181600.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 182000.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 182400.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 182800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 183200.0 ? -
25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 183600.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 184000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 184400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 184800.0 ? 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 185200.0 ? - 38 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 185600.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 186000.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 186400.0 ? - 35
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 186800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 187200.0 ? 38 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 187600.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188000.0 ? 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 188400.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 188800.0 ? 34 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 189200.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 189600.0 ? 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190000.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 190400.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 190800.0 ?
- 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 191200.0 ? 44 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 191600.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 192000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 192400.0 ? 17 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 192800.0 ? - 12 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 193200.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 193600.0
? - 48 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 194000.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 194400.0 ? 21 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 194800.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 195200.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 195600.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 196000.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 196400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 196800.0 ? - 33
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 197200.0 ? 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 197600.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 198000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 198800.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 199200.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 199600.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200000.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 200400.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 200800.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 201200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 201600.0 ? - 37
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 202000.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 202400.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 202800.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 203200.0 ? 4 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 203600.0 ? - 1 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 204000.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
204400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 204800.0 ? - 4 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 205200.0 ? - 12 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 205600.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
206000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 206400.0 ? 33 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 206800.0 ? - 5 : 0 ) ; tmp_n = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( tmp_b + ( ssGetTaskTime ( rtS , 2 ) >= 207200.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 207600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 208000.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 208400.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 208800.0 ? - 43 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 209200.0 ? 43 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 209600.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210000.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 210400.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 210800.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 211200.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 211600.0 ? -
2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 212400.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 212800.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 213200.0 ? 28 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 213600.0 ? - 19
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 214000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 214400.0 ? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 214800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215200.0 ? - 2 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 215600.0 ? 3 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 216000.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216400.0
? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 216800.0 ? 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 217200.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 217600.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218000.0 ? -
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 218400.0 ? - 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 218800.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 219200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 219600.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 220000.0 ? - 28 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 220400.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 220800.0 ?
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 221200.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 221600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 222000.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222400.0 ? - 11 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 222800.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 223200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 223600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224000.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 224400.0 ? - 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 224800.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 225200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 225600.0 ? 9
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 226000.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 226400.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 226800.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 227200.0 ? 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 228000.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 228400.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 228800.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 229200.0 ? 6 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 229600.0 ? - 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 230000.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 230400.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 230800.0 ? 8 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 231200.0 ? 40 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 231600.0 ? - 34 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
232000.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 232400.0 ? - 2 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 232800.0 ? - 5 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 233200.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 233600.0 ?
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 234000.0 ? - 33 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 234400.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 234800.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 235200.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 235600.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 236000.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 236400.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 236800.0 ? - 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 237200.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 237600.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 238000.0 ? - 44 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238400.0 ? 30
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 238800.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 239200.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 239600.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 240000.0 ? 13 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 240400.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 240800.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 241200.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 241600.0 ?
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 242000.0 ? 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 242400.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 242800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 243200.0 ? 15 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 243600.0 ? 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 244000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
244400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 244800.0 ? 21 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 245200.0 ? 21 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 245600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246000.0
? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 246400.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 246800.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 247200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 247600.0 ? -
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 248000.0 ? 45 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 248400.0 ? - 11 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 248800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 249200.0 ? -
23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 249600.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 250000.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250400.0
? - 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 250800.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 251200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 251600.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252000.0 ? -
7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 252400.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 252800.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 253200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 253600.0 ? - 7 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 254000.0 ? - 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 254400.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 254800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255200.0 ? -
20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 255600.0 ? 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 256000.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 256400.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 256800.0 ? 14
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 257200.0 ? - 1 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 257600.0 ? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 258000.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 258400.0 ? 6 :
0 ) ; tmp_l = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( tmp_n + ( ssGetTaskTime ( rtS , 2 ) >=
258800.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 259200.0 ? - 22 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 259600.0 ? 24 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 260000.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260400.0
? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 260800.0 ? - 25 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 261200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 261600.0 ? 7 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262000.0 ? 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 262400.0 ? - 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 262800.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 263200.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 263600.0 ? 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 264000.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 264400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 264800.0 ? - 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 265200.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 265600.0 ? 34 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 266000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266400.0
? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 266800.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 267200.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 267600.0 ? - 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268000.0 ? 25 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 268400.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 268800.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 269200.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 269600.0 ? 36
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 270000.0 ? - 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 270400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 270800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271200.0 ? 28
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 271600.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 272000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 272400.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 272800.0 ? - 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 273200.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 273600.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 274000.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274400.0 ? 7
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 274800.0 ? - 35 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 275200.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 275600.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276000.0 ? 4
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 276400.0 ? 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 276800.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 277200.0 ? 30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 277600.0 ? -
10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 278000.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 278400.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 278800.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279200.0 ? -
21 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 279600.0 ? 21 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 280000.0 ? - 15 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 280400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 280800.0 ? -
3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 281200.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 281600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 282000.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282400.0 ? -
15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 282800.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 283200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 283600.0 ? - 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284000.0 ? 39
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 284400.0 ? - 41 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 284800.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 285200.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 285600.0 ? - 39
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 286000.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 286400.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 286800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287200.0 ?
- 1 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 287600.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 288000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 288400.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 288800.0 ? 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 289200.0 ? - 16 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 289600.0 ? 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 290000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 290400.0 ? 17 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 290800.0 ? - 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 291200.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 292000.0 ? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292400.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 292800.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 293200.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 293600.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294000.0 ? 11
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 294400.0 ? - 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 294800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 295200.0 ? 37 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 295600.0 ? - 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 296000.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 296400.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 296800.0 ? - 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297200.0 ?
32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 297600.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 298000.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
298400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 298800.0 ? - 23 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 299200.0 ? - 11 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 299600.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300000.0 ?
- 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 300400.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 300800.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 301200.0 ? 25 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 301600.0 ? - 31
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 302000.0 ? 6 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 302400.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 302800.0 ? - 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 303200.0 ? - 2 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 303600.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 304000.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 304400.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 304800.0 ?
22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 305200.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 305600.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 306000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306400.0 ? 3
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 306800.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 307200.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 307600.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308000.0 ? 19 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 308400.0 ? 5 : 0 ) ) + ( ssGetTaskTime
( rtS , 2 ) >= 308800.0 ? - 32 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
309200.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 309600.0 ? 11 : 0 ) ;
tmp_d = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( tmp_l + ( ssGetTaskTime ( rtS , 2 ) >= 310000.0 ? 2
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 310400.0 ? - 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 310800.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
311200.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 311600.0 ? - 33 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 312000.0 ? 22 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 312800.0 ? - 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
313200.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 313600.0 ? 3 : 0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 314000.0 ? - 25 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 314400.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 314800.0
? - 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 315200.0 ? 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 315600.0 ? - 12 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 316000.0 ? 18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316400.0 ? -
9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 316800.0 ? - 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 317200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 317600.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318000.0 ? - 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 318400.0 ? 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 318800.0 ? - 39 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 319200.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 319600.0 ?
30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 320000.0 ? 9 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 320400.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 320800.0 ? - 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 321200.0 ? 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 321600.0 ? 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 322000.0 ? - 6 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 322400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 322800.0 ? 40
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 323200.0 ? - 31 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 323600.0 ? 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2
) >= 324000.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324400.0 ? - 14 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 324800.0 ? 18 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 325200.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 325600.0 ? 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326000.0 ? 8 : 0
) ) + ( ssGetTaskTime ( rtS , 2 ) >= 326400.0 ? - 22 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 326800.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 327200.0 ? 29 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 327600.0 ? - 24
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 328000.0 ? 34 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 328400.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 328800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 329200.0 ? -
11 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 329600.0 ? - 27 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 330000.0 ? 14 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 330400.0 ? 4 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 330800.0 ? - 8 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 331200.0 ? 37 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 331600.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 332000.0 ? - 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332400.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 332800.0 ? 12 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 333200.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 333600.0 ? 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334000.0 ? -
35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 334400.0 ? - 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 334800.0 ? 33 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 335200.0 ? - 38 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 335600.0 ? 35
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 336000.0 ? - 5 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 336400.0 ? - 33 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 336800.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 337200.0 ? 5
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 337600.0 ? 23 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 338000.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 338400.0 ? 6 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 338800.0 ) ) +
( ssGetTaskTime ( rtS , 2 ) >= 339200.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
339600.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 340000.0 ? - 36 : 0 )
) + ( ssGetTaskTime ( rtS , 2 ) >= 340400.0 ? 10 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 340800.0 ? 35 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341200.0
? - 23 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 341600.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 342000.0 ? - 20 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 342400.0 ? 22 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 342800.0 ? -
5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 343200.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 343600.0 ? 10 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 344000.0 ? 31 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344400.0 ? - 17
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 344800.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 345200.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 345600.0 ? -
33 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 346000.0 ? - 11 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 346400.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 346800.0 ? 40 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 347200.0 ? 2 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 347600.0 ? - 28 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 348400.0 ? - 7 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 348800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 349200.0 ? - 5 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 349600.0 ? 20 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 350000.0 ? 23 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 350400.0 ? - 8 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 350800.0 ? -
12 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 351200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 351600.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 352000.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352400.0 ? 3 :
0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 352800.0 ? - 36 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 353200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 353600.0 ? 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354000.0 ? - 34
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 354400.0 ? 4 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 354800.0 ? - 1 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 355200.0 ? 13 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 355600.0 ? - 18
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 356000.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 356400.0 ? 20 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 356800.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 357200.0 ? 6
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 357600.0 ? 7 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 358000.0 ? - 14 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 358400.0 ? - 2 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 358800.0 ?
27 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 359200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 359600.0 ? 26 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 360000.0 ? - 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 360400.0 ? -
18 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 360800.0 ? 10 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 361200.0 ? - 3 : 0 ) ; bkywyomtj0 = ( ( ( ( ( (
( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( real_T ) ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
( ( ( ( ( ( ( ( tmp_d + ( ssGetTaskTime ( rtS , 2 ) >= 361600.0 ? 14 : 0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 362000.0 ? - 26 : 0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 362400.0 ? 15 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 362800.0
? 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 363200.0 ? - 2 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 363600.0 ? 11 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 364000.0 ? - 17 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 364400.0 ? 8
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 364800.0 ? 14 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 365200.0 ? - 30 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 365600.0 ? - 3 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366000.0 ?
30 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 366400.0 ? - 40 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 366800.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 367200.0 ? 16 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 367600.0 ? - 10
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 368000.0 ? 24 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 368400.0 ? - 25 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 368800.0 ? 5 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 369200.0 ? 15
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 369600.0 ? - 29 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 370000.0 ? 27 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 370400.0 ? - 36 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 370800.0 ? 41
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 371200.0 ? - 8 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 371600.0 ? - 37 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 372000.0 ? 45 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372400.0 ? -
42 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 372800.0 ? - 3 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 373200.0 ? 19 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 373600.0 ? 24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374000.0 ? - 27
: 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 374400.0 ? 17 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 374800.0 ? 12 : 0 ) ) + ( ssGetTaskTime ( rtS ,
2 ) >= 375200.0 ? - 9 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 375600.0 ? -
24 : 0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 376000.0 ? 13 : 0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 376400.0 ? - 26 : 0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 376800.0 ? 8.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 377200.0 ?
13.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 377600.0 ? 24.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 378000.0 ? - 19.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 378400.0 ? 6.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
378800.0 ? 13.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 379200.0 ? - 8.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 379600.0 ? - 31.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 380000.0 ? 38.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 380400.0 ? 5.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
380800.0 ? - 47.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 381200.0 ? 15.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 381600.0 ? - 8.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 382000.0 ? 19.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 382400.0 ? - 11.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
382800.0 ? 30.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 383200.0 ? - 1.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 383600.0 ? - 45.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 384000.0 ? 41.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 384400.0 ? - 26.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
384800.0 ? 12.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 385200.0 ? - 22.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 386000.0 ? 8.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 386400.0 ? 19.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 386800.0 ? 3.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
387200.0 ? - 35.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 387600.0 ? 7.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 388000.0 ? 12.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 388400.0 ? - 7.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 388800.0 ? - 7.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
389200.0 ? 31.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 389600.0 ? - 36.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 390000.0 ? 9.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 390400.0 ? 20.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 390800.0 ? - 28.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
391200.0 ? 39.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 391600.0 ? - 15.0
: 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 392000.0 ? - 23.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 392400.0 ? 4.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS
, 2 ) >= 392800.0 ? 29.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 393200.0
? - 14.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 393600.0 ? 15.0 : 0.0 ) )
+ ( ssGetTaskTime ( rtS , 2 ) >= 394000.0 ? - 35.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 394400.0 ? 24.0 : 0.0 ) ) + ( ssGetTaskTime (
rtS , 2 ) >= 394800.0 ? - 1.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >=
395200.0 ? 2.0 : 0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 395600.0 ? - 9.0 :
0.0 ) ) + ( ssGetTaskTime ( rtS , 2 ) >= 396000.0 ? 9.0 : 0.0 ) ) + (
ssGetTaskTime ( rtS , 2 ) >= 396400.0 ? 4.0 : 0.0 ) ; break ; default :
bkywyomtj0 = ssGetTaskTime ( rtS , 2 ) >= 72000.0 ? 70.0 : 0.0 ; break ; } if
( bkywyomtj0 > rtP . Saturation_UpperSat ) { rtB . amqerpar2b = rtP .
Saturation_UpperSat ; } else if ( bkywyomtj0 < rtP . Saturation_LowerSat ) {
rtB . amqerpar2b = rtP . Saturation_LowerSat ; } else { rtB . amqerpar2b =
bkywyomtj0 ; } rtDW . hxixz0diaj = rtDW . cijhhdchyo ? rtDW . hxixz0diaj :
29622272U ; rtDW . cijhhdchyo = true ; bkywyomtj0 =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hxixz0diaj ) ; rtDW . phkyglsksj = rtDW
. ik50j3b4la ? rtDW . phkyglsksj : 720896U ; rtDW . ik50j3b4la = true ;
applyStandardDeviation = 1.7320508075688772 * rt_nrand_Upu32_Yd_f_pw_snf ( &
rtDW . phkyglsksj ) ; rtDW . fkpuglvoce = rtDW . ercrtsl3ul ? rtDW .
fkpuglvoce : 786432U ; rtDW . ercrtsl3ul = true ; applyStandardDeviation_p =
1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . fkpuglvoce ) ;
rtDW . mxczgh10dw = rtDW . ajg1qa13qd ? rtDW . mxczgh10dw : 851968U ; rtDW .
ajg1qa13qd = true ; applyStandardDeviation_e = 1.4142135623730951 *
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mxczgh10dw ) ; rtDW . nhjl40zo3t = rtDW
. no0onatjsa ? rtDW . nhjl40zo3t : 917504U ; rtDW . no0onatjsa = true ;
applyStandardDeviation_i = 1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf (
& rtDW . nhjl40zo3t ) ; rtDW . pvkjz3veq1 = rtDW . f1vped4bnl ? rtDW .
pvkjz3veq1 : 983040U ; rtDW . f1vped4bnl = true ; applyStandardDeviation_m =
1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . pvkjz3veq1 ) ;
rtDW . mfqkf0zqeo = rtDW . o0b14vit54 ? rtDW . mfqkf0zqeo : 1048576U ; rtDW .
o0b14vit54 = true ; applyStandardDeviation_g = 1.4142135623730951 *
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mfqkf0zqeo ) ; rtDW . ksfiloike2 = rtDW
. ltv1e4zdnf ? rtDW . ksfiloike2 : 1114112U ; rtDW . ltv1e4zdnf = true ;
applyStandardDeviation_j = 1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf (
& rtDW . ksfiloike2 ) ; rtDW . l2kheao0b5 = rtDW . cbpmfl3daa ? rtDW .
l2kheao0b5 : 1179648U ; rtDW . cbpmfl3daa = true ; applyStandardDeviation_f =
1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . l2kheao0b5 ) ;
switch ( ( int32_T ) rtP . ruido1_SelectedSignal ) { case 1 : break ; case 2
: bkywyomtj0 = applyStandardDeviation ; break ; case 3 : bkywyomtj0 =
applyStandardDeviation_p ; break ; case 4 : bkywyomtj0 =
applyStandardDeviation_e ; break ; case 5 : bkywyomtj0 =
applyStandardDeviation_i ; break ; case 6 : bkywyomtj0 =
applyStandardDeviation_m ; break ; case 7 : bkywyomtj0 =
applyStandardDeviation_g ; break ; case 8 : bkywyomtj0 =
applyStandardDeviation_j ; break ; case 9 : bkywyomtj0 =
applyStandardDeviation_f ; break ; default : bkywyomtj0 = 0.0 ; break ; } rtB
. hz5ifhc25c = ( rtB . c2nnsvritk - rtB . acnxapdnky ) + bkywyomtj0 ; rtDW .
kbdgvwackz = rtDW . ihzo0v2eqx ? rtDW . kbdgvwackz : 655360U ; rtDW .
ihzo0v2eqx = true ; bkywyomtj0 = 0.44721359549995793 *
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . kbdgvwackz ) ; rtDW . lbxi5wwnx3 = rtDW
. opu3gm1und ? rtDW . lbxi5wwnx3 : 720896U ; rtDW . opu3gm1und = true ;
applyStandardDeviation = 0.44721359549995793 * rt_nrand_Upu32_Yd_f_pw_snf ( &
rtDW . lbxi5wwnx3 ) ; rtDW . hc55zqdtz0 = rtDW . loyc4qmd00 ? rtDW .
hc55zqdtz0 : 786432U ; rtDW . loyc4qmd00 = true ; applyStandardDeviation_p =
0.44721359549995793 * rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hc55zqdtz0 ) ;
rtDW . mqicor4wcz = rtDW . dlka5jhs0h ? rtDW . mqicor4wcz : 851968U ; rtDW .
dlka5jhs0h = true ; applyStandardDeviation_e = 0.44721359549995793 *
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mqicor4wcz ) ; rtDW . h0wbwp43sy = rtDW
. ccq1r4uodm ? rtDW . h0wbwp43sy : 917504U ; rtDW . ccq1r4uodm = true ;
applyStandardDeviation_i = 0.44721359549995793 * rt_nrand_Upu32_Yd_f_pw_snf (
& rtDW . h0wbwp43sy ) ; rtDW . n3yhdhd3sz = rtDW . eeyqmg1sps ? rtDW .
n3yhdhd3sz : 983040U ; rtDW . eeyqmg1sps = true ; applyStandardDeviation_m =
1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . n3yhdhd3sz ) ;
rtDW . bbtqzyjvdv = rtDW . aiqbe2qv5w ? rtDW . bbtqzyjvdv : 1048576U ; rtDW .
aiqbe2qv5w = true ; applyStandardDeviation_g = 1.4142135623730951 *
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . bbtqzyjvdv ) ; rtDW . nr0mtfjxwf = rtDW
. arn25zbrew ? rtDW . nr0mtfjxwf : 1114112U ; rtDW . arn25zbrew = true ;
applyStandardDeviation_j = 1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf (
& rtDW . nr0mtfjxwf ) ; rtDW . dzabhw2v3z = rtDW . k4odt4vyi3 ? rtDW .
dzabhw2v3z : 1179648U ; rtDW . k4odt4vyi3 = true ; applyStandardDeviation_f =
1.4142135623730951 * rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . dzabhw2v3z ) ;
switch ( ( int32_T ) rtP . ruido_SelectedSignal ) { case 1 : rtB . ns50kkurdv
= bkywyomtj0 ; break ; case 2 : rtB . ns50kkurdv = applyStandardDeviation ;
break ; case 3 : rtB . ns50kkurdv = applyStandardDeviation_p ; break ; case 4
: rtB . ns50kkurdv = applyStandardDeviation_e ; break ; case 5 : rtB .
ns50kkurdv = applyStandardDeviation_i ; break ; case 6 : rtB . ns50kkurdv =
applyStandardDeviation_m ; break ; case 7 : rtB . ns50kkurdv =
applyStandardDeviation_g ; break ; case 8 : rtB . ns50kkurdv =
applyStandardDeviation_j ; break ; case 9 : rtB . ns50kkurdv =
applyStandardDeviation_f ; break ; default : rtB . ns50kkurdv = 0.0 ; break ;
} if ( ssIsSpecialSampleHit ( rtS , 4 , 2 , 0 ) ) { rtB . evoblqrjee = rtB .
hz5ifhc25c ; } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid )
{ { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( rtDW . n2alg3gtxbm .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . n2alg3gtxbm .
AQHandles , ssGetTaskTime ( rtS , 3 ) , ( char * ) & rtB . c2nnsvritk + 0 ) ;
} } } { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( rtDW . avu4vt3ihx .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . avu4vt3ihx .
AQHandles , ssGetTaskTime ( rtS , 3 ) , ( char * ) & rtB . kqhghyeq3z + 0 ) ;
} } } { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( rtDW . pkvrcopyelh .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . pkvrcopyelh .
AQHandles , ssGetTaskTime ( rtS , 3 ) , ( char * ) & rtB . nwa0blftqa + 0 ) ;
} } } { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( rtDW . ny23d4etjaa .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . ny23d4etjaa .
AQHandles , ssGetTaskTime ( rtS , 3 ) , ( char * ) & rtB . acnxapdnky + 0 ) ;
} } } { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( rtDW . avu4vt3ihx4 .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . avu4vt3ihx4 .
AQHandles , ssGetTaskTime ( rtS , 3 ) , ( char * ) & rtB . amqerpar2b + 0 ) ;
} } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) { real_T
u0 ; rtB . hlqeedqmkd = ( rtP . PIDController_D * rtB . evoblqrjee - rtDW .
dwaftwnef5 ) * rtP . PIDController_N ; u0 = ( rtP . PIDController_P * rtB .
evoblqrjee + rtDW . f1gmat2bv1 ) + rtB . hlqeedqmkd ; if ( u0 > rtP .
PIDController_UpperSaturationLimit ) { rtB . nwa0blftqa = rtP .
PIDController_UpperSaturationLimit ; } else if ( u0 < rtP .
PIDController_LowerSaturationLimit ) { rtB . nwa0blftqa = rtP .
PIDController_LowerSaturationLimit ; } else { rtB . nwa0blftqa = u0 ; } rtB .
hqhvmmqb2r = rtP . PIDController_I * rtB . evoblqrjee ; if ( rtB . nwa0blftqa
> rtP . Saturador1_UpperSat ) { rtB . cawe1pel2l = rtP . Saturador1_UpperSat
; } else if ( rtB . nwa0blftqa < rtP . Saturador1_LowerSat ) { rtB .
cawe1pel2l = rtP . Saturador1_LowerSat ; } else { rtB . cawe1pel2l = rtB .
nwa0blftqa ; } { if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if ( rtDW .
n52vpgrthw . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
n52vpgrthw . AQHandles , ssGetTaskTime ( rtS , 4 ) , ( char * ) & rtB .
cawe1pel2l + 0 ) ; } } } rtB . p2gs34a42l = rtP . C1_Gain * rtB . cawe1pel2l
; rtB . acnxapdnky = rtB . m4eclbfi40 ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID5 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { MdlUpdateTID4 ( tid ) ;
} UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID3 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4 ( int_T tid ) { rtDW .
f1gmat2bv1 += rtP . Integrator_gainval * rtB . hqhvmmqb2r ; rtDW . dwaftwnef5
+= rtP . Filter_gainval * rtB . hlqeedqmkd ; UNUSED_PARAMETER ( tid ) ; }
void MdlUpdateTID5 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> n5jaiqo4q1 = rtB . bnnrwyns0c ; _rtXdot -> oijbjoorjx =
rtB . kv0eqywsiz ; if ( ( ( rtX . kq0qmjau05 > rtP . Integrador_LowerSat ) &&
( rtX . kq0qmjau05 < rtP . Integrador_UpperSat ) ) || ( ( rtX . kq0qmjau05 <=
rtP . Integrador_LowerSat ) && ( rtB . eicjvshfeq > 0.0 ) ) || ( ( rtX .
kq0qmjau05 >= rtP . Integrador_UpperSat ) && ( rtB . eicjvshfeq < 0.0 ) ) ) {
_rtXdot -> kq0qmjau05 = rtB . eicjvshfeq ; } else { _rtXdot -> kq0qmjau05 =
0.0 ; } } void MdlProjection ( void ) { } void MdlTerminate ( void ) { { if (
rtDW . n2alg3gtxb . AQHandles ) { sdiTerminateStreaming ( & rtDW . n2alg3gtxb
. AQHandles ) ; } } { if ( rtDW . pkvrcopyel . AQHandles ) {
sdiTerminateStreaming ( & rtDW . pkvrcopyel . AQHandles ) ; } } { if ( rtDW .
ny23d4etja . AQHandles ) { sdiTerminateStreaming ( & rtDW . ny23d4etja .
AQHandles ) ; } } { if ( rtDW . f2mr0nuv1k . AQHandles ) {
sdiTerminateStreaming ( & rtDW . f2mr0nuv1k . AQHandles ) ; } } { if ( rtDW .
n2alg3gtxbm . AQHandles ) { sdiTerminateStreaming ( & rtDW . n2alg3gtxbm .
AQHandles ) ; } } { if ( rtDW . avu4vt3ihx . AQHandles ) {
sdiTerminateStreaming ( & rtDW . avu4vt3ihx . AQHandles ) ; } } { if ( rtDW .
pkvrcopyelh . AQHandles ) { sdiTerminateStreaming ( & rtDW . pkvrcopyelh .
AQHandles ) ; } } { if ( rtDW . ny23d4etjaa . AQHandles ) {
sdiTerminateStreaming ( & rtDW . ny23d4etjaa . AQHandles ) ; } } { if ( rtDW
. avu4vt3ihx4 . AQHandles ) { sdiTerminateStreaming ( & rtDW . avu4vt3ihx4 .
AQHandles ) ; } } { if ( rtDW . n52vpgrthw . AQHandles ) {
sdiTerminateStreaming ( & rtDW . n52vpgrthw . AQHandles ) ; } } } static void
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) {
memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_SistemaEstanques_PID_discreto_cacheBitFieldToMxArray ( mxArray * destArray
, mwIndex i , int j , uint_T bitVal ) ; static void
mr_SistemaEstanques_PID_discreto_cacheBitFieldToMxArray ( mxArray * destArray
, mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i ,
j , mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_SistemaEstanques_PID_discreto_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_SistemaEstanques_PID_discreto_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = (
uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return
varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_SistemaEstanques_PID_discreto_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void
mr_SistemaEstanques_PID_discreto_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_SistemaEstanques_PID_discreto_restoreDataFromMxArrayWithOffset ( void
* destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_SistemaEstanques_PID_discreto_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void
mr_SistemaEstanques_PID_discreto_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_SistemaEstanques_PID_discreto_extractBitFieldFromCellArrayWithOffset (
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) ; static uint_T
mr_SistemaEstanques_PID_discreto_extractBitFieldFromCellArrayWithOffset (
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray *
mr_SistemaEstanques_PID_discreto_GetDWork ( ) { static const char *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const
void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char *
rtdwDataFieldNames [ 38 ] = { "rtDW.f1gmat2bv1" , "rtDW.dwaftwnef5" ,
"rtDW.hxixz0diaj" , "rtDW.phkyglsksj" , "rtDW.fkpuglvoce" , "rtDW.mxczgh10dw"
, "rtDW.nhjl40zo3t" , "rtDW.pvkjz3veq1" , "rtDW.mfqkf0zqeo" ,
"rtDW.ksfiloike2" , "rtDW.l2kheao0b5" , "rtDW.kbdgvwackz" , "rtDW.lbxi5wwnx3"
, "rtDW.hc55zqdtz0" , "rtDW.mqicor4wcz" , "rtDW.h0wbwp43sy" ,
"rtDW.n3yhdhd3sz" , "rtDW.bbtqzyjvdv" , "rtDW.nr0mtfjxwf" , "rtDW.dzabhw2v3z"
, "rtDW.cijhhdchyo" , "rtDW.ik50j3b4la" , "rtDW.ercrtsl3ul" ,
"rtDW.ajg1qa13qd" , "rtDW.no0onatjsa" , "rtDW.f1vped4bnl" , "rtDW.o0b14vit54"
, "rtDW.ltv1e4zdnf" , "rtDW.cbpmfl3daa" , "rtDW.ihzo0v2eqx" ,
"rtDW.opu3gm1und" , "rtDW.loyc4qmd00" , "rtDW.dlka5jhs0h" , "rtDW.ccq1r4uodm"
, "rtDW.eeyqmg1sps" , "rtDW.aiqbe2qv5w" , "rtDW.arn25zbrew" ,
"rtDW.k4odt4vyi3" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
38 , rtdwDataFieldNames ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 0 , (
const void * ) & ( rtDW . f1gmat2bv1 ) , sizeof ( rtDW . f1gmat2bv1 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 1 , (
const void * ) & ( rtDW . dwaftwnef5 ) , sizeof ( rtDW . dwaftwnef5 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 2 , (
const void * ) & ( rtDW . hxixz0diaj ) , sizeof ( rtDW . hxixz0diaj ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 3 , (
const void * ) & ( rtDW . phkyglsksj ) , sizeof ( rtDW . phkyglsksj ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 4 , (
const void * ) & ( rtDW . fkpuglvoce ) , sizeof ( rtDW . fkpuglvoce ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 5 , (
const void * ) & ( rtDW . mxczgh10dw ) , sizeof ( rtDW . mxczgh10dw ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 6 , (
const void * ) & ( rtDW . nhjl40zo3t ) , sizeof ( rtDW . nhjl40zo3t ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 7 , (
const void * ) & ( rtDW . pvkjz3veq1 ) , sizeof ( rtDW . pvkjz3veq1 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 8 , (
const void * ) & ( rtDW . mfqkf0zqeo ) , sizeof ( rtDW . mfqkf0zqeo ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 9 , (
const void * ) & ( rtDW . ksfiloike2 ) , sizeof ( rtDW . ksfiloike2 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 10 , (
const void * ) & ( rtDW . l2kheao0b5 ) , sizeof ( rtDW . l2kheao0b5 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 11 , (
const void * ) & ( rtDW . kbdgvwackz ) , sizeof ( rtDW . kbdgvwackz ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 12 , (
const void * ) & ( rtDW . lbxi5wwnx3 ) , sizeof ( rtDW . lbxi5wwnx3 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 13 , (
const void * ) & ( rtDW . hc55zqdtz0 ) , sizeof ( rtDW . hc55zqdtz0 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 14 , (
const void * ) & ( rtDW . mqicor4wcz ) , sizeof ( rtDW . mqicor4wcz ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 15 , (
const void * ) & ( rtDW . h0wbwp43sy ) , sizeof ( rtDW . h0wbwp43sy ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 16 , (
const void * ) & ( rtDW . n3yhdhd3sz ) , sizeof ( rtDW . n3yhdhd3sz ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 17 , (
const void * ) & ( rtDW . bbtqzyjvdv ) , sizeof ( rtDW . bbtqzyjvdv ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 18 , (
const void * ) & ( rtDW . nr0mtfjxwf ) , sizeof ( rtDW . nr0mtfjxwf ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 19 , (
const void * ) & ( rtDW . dzabhw2v3z ) , sizeof ( rtDW . dzabhw2v3z ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 20 , (
const void * ) & ( rtDW . cijhhdchyo ) , sizeof ( rtDW . cijhhdchyo ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 21 , (
const void * ) & ( rtDW . ik50j3b4la ) , sizeof ( rtDW . ik50j3b4la ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 22 , (
const void * ) & ( rtDW . ercrtsl3ul ) , sizeof ( rtDW . ercrtsl3ul ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 23 , (
const void * ) & ( rtDW . ajg1qa13qd ) , sizeof ( rtDW . ajg1qa13qd ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 24 , (
const void * ) & ( rtDW . no0onatjsa ) , sizeof ( rtDW . no0onatjsa ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 25 , (
const void * ) & ( rtDW . f1vped4bnl ) , sizeof ( rtDW . f1vped4bnl ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 26 , (
const void * ) & ( rtDW . o0b14vit54 ) , sizeof ( rtDW . o0b14vit54 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 27 , (
const void * ) & ( rtDW . ltv1e4zdnf ) , sizeof ( rtDW . ltv1e4zdnf ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 28 , (
const void * ) & ( rtDW . cbpmfl3daa ) , sizeof ( rtDW . cbpmfl3daa ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 29 , (
const void * ) & ( rtDW . ihzo0v2eqx ) , sizeof ( rtDW . ihzo0v2eqx ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 30 , (
const void * ) & ( rtDW . opu3gm1und ) , sizeof ( rtDW . opu3gm1und ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 31 , (
const void * ) & ( rtDW . loyc4qmd00 ) , sizeof ( rtDW . loyc4qmd00 ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 32 , (
const void * ) & ( rtDW . dlka5jhs0h ) , sizeof ( rtDW . dlka5jhs0h ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 33 , (
const void * ) & ( rtDW . ccq1r4uodm ) , sizeof ( rtDW . ccq1r4uodm ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 34 , (
const void * ) & ( rtDW . eeyqmg1sps ) , sizeof ( rtDW . eeyqmg1sps ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 35 , (
const void * ) & ( rtDW . aiqbe2qv5w ) , sizeof ( rtDW . aiqbe2qv5w ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 36 , (
const void * ) & ( rtDW . arn25zbrew ) , sizeof ( rtDW . arn25zbrew ) ) ;
mr_SistemaEstanques_PID_discreto_cacheDataAsMxArray ( rtdwData , 0 , 37 , (
const void * ) & ( rtDW . k4odt4vyi3 ) , sizeof ( rtDW . k4odt4vyi3 ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_SistemaEstanques_PID_discreto_SetDWork ( const mxArray * ssDW ) { ( void )
ssDW ; mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) &
( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. f1gmat2bv1 ) , rtdwData , 0 , 0 , sizeof ( rtDW . f1gmat2bv1 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. dwaftwnef5 ) , rtdwData , 0 , 1 , sizeof ( rtDW . dwaftwnef5 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. hxixz0diaj ) , rtdwData , 0 , 2 , sizeof ( rtDW . hxixz0diaj ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. phkyglsksj ) , rtdwData , 0 , 3 , sizeof ( rtDW . phkyglsksj ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. fkpuglvoce ) , rtdwData , 0 , 4 , sizeof ( rtDW . fkpuglvoce ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. mxczgh10dw ) , rtdwData , 0 , 5 , sizeof ( rtDW . mxczgh10dw ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. nhjl40zo3t ) , rtdwData , 0 , 6 , sizeof ( rtDW . nhjl40zo3t ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. pvkjz3veq1 ) , rtdwData , 0 , 7 , sizeof ( rtDW . pvkjz3veq1 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. mfqkf0zqeo ) , rtdwData , 0 , 8 , sizeof ( rtDW . mfqkf0zqeo ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ksfiloike2 ) , rtdwData , 0 , 9 , sizeof ( rtDW . ksfiloike2 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. l2kheao0b5 ) , rtdwData , 0 , 10 , sizeof ( rtDW . l2kheao0b5 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. kbdgvwackz ) , rtdwData , 0 , 11 , sizeof ( rtDW . kbdgvwackz ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. lbxi5wwnx3 ) , rtdwData , 0 , 12 , sizeof ( rtDW . lbxi5wwnx3 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. hc55zqdtz0 ) , rtdwData , 0 , 13 , sizeof ( rtDW . hc55zqdtz0 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. mqicor4wcz ) , rtdwData , 0 , 14 , sizeof ( rtDW . mqicor4wcz ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. h0wbwp43sy ) , rtdwData , 0 , 15 , sizeof ( rtDW . h0wbwp43sy ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. n3yhdhd3sz ) , rtdwData , 0 , 16 , sizeof ( rtDW . n3yhdhd3sz ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. bbtqzyjvdv ) , rtdwData , 0 , 17 , sizeof ( rtDW . bbtqzyjvdv ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. nr0mtfjxwf ) , rtdwData , 0 , 18 , sizeof ( rtDW . nr0mtfjxwf ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. dzabhw2v3z ) , rtdwData , 0 , 19 , sizeof ( rtDW . dzabhw2v3z ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. cijhhdchyo ) , rtdwData , 0 , 20 , sizeof ( rtDW . cijhhdchyo ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ik50j3b4la ) , rtdwData , 0 , 21 , sizeof ( rtDW . ik50j3b4la ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ercrtsl3ul ) , rtdwData , 0 , 22 , sizeof ( rtDW . ercrtsl3ul ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ajg1qa13qd ) , rtdwData , 0 , 23 , sizeof ( rtDW . ajg1qa13qd ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. no0onatjsa ) , rtdwData , 0 , 24 , sizeof ( rtDW . no0onatjsa ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. f1vped4bnl ) , rtdwData , 0 , 25 , sizeof ( rtDW . f1vped4bnl ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. o0b14vit54 ) , rtdwData , 0 , 26 , sizeof ( rtDW . o0b14vit54 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ltv1e4zdnf ) , rtdwData , 0 , 27 , sizeof ( rtDW . ltv1e4zdnf ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. cbpmfl3daa ) , rtdwData , 0 , 28 , sizeof ( rtDW . cbpmfl3daa ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ihzo0v2eqx ) , rtdwData , 0 , 29 , sizeof ( rtDW . ihzo0v2eqx ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. opu3gm1und ) , rtdwData , 0 , 30 , sizeof ( rtDW . opu3gm1und ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. loyc4qmd00 ) , rtdwData , 0 , 31 , sizeof ( rtDW . loyc4qmd00 ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. dlka5jhs0h ) , rtdwData , 0 , 32 , sizeof ( rtDW . dlka5jhs0h ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ccq1r4uodm ) , rtdwData , 0 , 33 , sizeof ( rtDW . ccq1r4uodm ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. eeyqmg1sps ) , rtdwData , 0 , 34 , sizeof ( rtDW . eeyqmg1sps ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. aiqbe2qv5w ) , rtdwData , 0 , 35 , sizeof ( rtDW . aiqbe2qv5w ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. arn25zbrew ) , rtdwData , 0 , 36 , sizeof ( rtDW . arn25zbrew ) ) ;
mr_SistemaEstanques_PID_discreto_restoreDataFromMxArray ( ( void * ) & ( rtDW
. k4odt4vyi3 ) , rtdwData , 0 , 37 , sizeof ( rtDW . k4odt4vyi3 ) ) ; } }
mxArray * mr_SistemaEstanques_PID_discreto_GetSimStateDisallowedBlocks ( ) {
mxArray * data = mxCreateCellMatrix ( 5 , 3 ) ; mwIndex subs [ 2 ] , offset ;
{ static const char * blockType [ 5 ] = { "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , } ; static const char * blockPath [ 5 ] = {
"SistemaEstanques_PID_discreto/Tc" , "SistemaEstanques_PID_discreto/Tr" ,
"SistemaEstanques_PID_discreto/hc" , "SistemaEstanques_PID_discreto/Scope" ,
"SistemaEstanques_PID_discreto/f" , } ; static const int reason [ 5 ] = { 0 ,
0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 5 ; ++ ( subs [ 0 ] )
) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 3 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 5 ) ; ssSetNumBlocks ( rtS , 158 ) ;
ssSetNumBlockIO ( rtS , 25 ) ; ssSetNumBlockParams ( rtS , 69 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.05 ) ; ssSetSampleTime ( rtS , 2 , 0.1 ) ;
ssSetSampleTime ( rtS , 3 , 1.0 ) ; ssSetSampleTime ( rtS , 4 , 15.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ;
ssSetOffsetTime ( rtS , 4 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1363514817U ) ; ssSetChecksumVal ( rtS , 1 ,
1699563187U ) ; ssSetChecksumVal ( rtS , 2 , 4135759033U ) ; ssSetChecksumVal
( rtS , 3 , 3873568147U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; } } mdlSampleHits [ 0 ] = 1 ; ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; } {
static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; ( void
) memset ( ( void * ) & mdlPerTaskSampleHits [ 0 ] , 0 , 5 * 5 * sizeof (
int_T ) ) ; ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] )
; } ssSetSolverMode ( rtS , SOLVER_MODE_MULTITASKING ) ; { ssSetBlockIO ( rtS
, ( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 ,
sizeof ( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS
, x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 22 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } SistemaEstanques_PID_discreto_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"SistemaEstanques_PID_discreto" ) ; ssSetPath ( rtS ,
"SistemaEstanques_PID_discreto" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 144000.0 ) ; ssSetStepSize ( rtS , 0.05 ) ; ssSetFixedStepSize ( rtS ,
0.05 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "DSTATE" , "DSTATE" } ; static const char_T
* rt_LoggedStateBlockNames [ ] = {
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura C&#xF3;nico/Integrator"
,
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculaci&#xF3;n/Integrator"
, "SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Integrador" ,
"SistemaEstanques_PID_discreto/PID Controller/Integrator/Discrete/Integrator"
,
 "SistemaEstanques_PID_discreto/PID Controller/Filter/Disc. Forward Euler Filter/Filter"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
} ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 0 , 1 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 5 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 5 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . n5jaiqo4q1 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . oijbjoorjx ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . kq0qmjau05 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtDW . f1gmat2bv1 ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . dwaftwnef5 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode3" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 1363514817U ) ; ssSetChecksumVal ( rtS , 1 ,
1699563187U ) ; ssSetChecksumVal ( rtS , 2 , 4135759033U ) ; ssSetChecksumVal
( rtS , 3 , 3873568147U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_SistemaEstanques_PID_discreto_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_SistemaEstanques_PID_discreto_GetDWork ) ; slsaSetWorkFcnForSimTargetOP (
rtS , mr_SistemaEstanques_PID_discreto_SetDWork ) ; rtP . Integrador_UpperSat
= rtInf ; rtP . Saturador2_UpperSat = rtInf ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 5 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID5 ( tid ) ; }
