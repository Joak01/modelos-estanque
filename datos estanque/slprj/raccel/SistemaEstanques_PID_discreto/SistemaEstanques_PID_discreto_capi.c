#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "SistemaEstanques_PID_discreto_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "SistemaEstanques_PID_discreto.h"
#include "SistemaEstanques_PID_discreto_capi.h"
#include "SistemaEstanques_PID_discreto_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 1 , 0 , TARGET_STRING ( "SistemaEstanques_PID_discreto/Sum3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Zero-Order Hold" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Zero-Order Hold2" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Waveform Generator/Converter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/ruido/MultiportSwitch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/C1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 7 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Integrador" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturador1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 11 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/PID Controller/I Gain/Internal Parameters/Integral Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 19 , 0 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/PID Controller/N Gain/Internal Parameters/Filter Coefficient"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 20 , 0 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 21 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING ( "P" ) , 0
, 0 , 0 } , { 22 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING ( "I" ) , 0
, 0 , 0 } , { 23 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING ( "D" ) , 0
, 0 , 0 } , { 24 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING ( "N" ) , 0
, 0 , 0 } , { 25 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 26 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques" ) , TARGET_STRING ( "h0"
) , 0 , 0 , 0 } , { 30 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques" ) , TARGET_STRING (
"T0c" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques" ) , TARGET_STRING (
"T0r" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques" ) , TARGET_STRING (
"Fout_null" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Waveform Generator" ) , TARGET_STRING (
"SelectedSignal" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"SistemaEstanques_PID_discreto/ruido" ) , TARGET_STRING ( "SelectedSignal" )
, 0 , 0 , 0 } , { 35 , TARGET_STRING ( "SistemaEstanques_PID_discreto/ruido1"
) , TARGET_STRING ( "SelectedSignal" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 37 , TARGET_STRING ( "SistemaEstanques_PID_discreto/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp1" ) ,
TARGET_STRING ( "slope" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp1" ) ,
TARGET_STRING ( "start" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp1" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp2" ) ,
TARGET_STRING ( "slope" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp2" ) ,
TARGET_STRING ( "start" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp2" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Waveform Generator"
) , TARGET_STRING ( "SelectedSignal" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/C2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 48 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/K3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/2K2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/3K1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/C1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/beta" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Integrador" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING
( "SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Integrador" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING
( "SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturador1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturador1" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturador2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturador2" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation1" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Saturation2" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 68 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/cp" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/cp1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/ha" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/km" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/rho" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Cónico/rho1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/M"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/cp"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/cp1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/ha"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/km"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/km1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 83 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/rho"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 84 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/rho1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/Sistema de Estanques/Temperatura Recirculación/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
 "SistemaEstanques_PID_discreto/PID Controller/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"SistemaEstanques_PID_discreto/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp1/Step" ) ,
TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"SistemaEstanques_PID_discreto/Sistema de Estanques/Nivel/Ramp2/Step" ) ,
TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . m4eclbfi40 , & rtB . hz5ifhc25c ,
& rtB . evoblqrjee , & rtB . acnxapdnky , & rtB . c2nnsvritk , & rtB .
ns50kkurdv , & rtB . p2gs34a42l , & rtB . kqhghyeq3z , & rtB . eicjvshfeq , &
rtB . hlxlc4tizq , & rtB . cawe1pel2l , & rtB . amqerpar2b , & rtB .
pamg2ltvgy , & rtB . lku50azrkb , & rtB . m2w3hx33rl , & rtB . bnnrwyns0c , &
rtB . ga0bmsoaao , & rtB . kv0eqywsiz , & rtB . hqhvmmqb2r , & rtB .
hlqeedqmkd , & rtB . nwa0blftqa , & rtP . PIDController_P , & rtP .
PIDController_I , & rtP . PIDController_D , & rtP . PIDController_N , & rtP .
PIDController_InitialConditionForIntegrator , & rtP .
PIDController_InitialConditionForFilter , & rtP .
PIDController_UpperSaturationLimit , & rtP .
PIDController_LowerSaturationLimit , & rtP . SistemadeEstanques_h0 , & rtP .
SistemadeEstanques_T0c , & rtP . SistemadeEstanques_T0r , & rtP .
SistemadeEstanques_Fout_null , & rtP .
WaveformGenerator_SelectedSignal_f3od4jcqqc , & rtP . ruido_SelectedSignal ,
& rtP . ruido1_SelectedSignal , & rtP . Constant_Value , & rtP .
Constant1_Value , & rtP . Ramp1_slope , & rtP . Ramp1_start , & rtP .
Ramp1_InitialOutput , & rtP . Ramp2_slope , & rtP . Ramp2_start , & rtP .
Ramp2_InitialOutput , & rtP . WaveformGenerator_SelectedSignal , & rtP .
C2_Value , & rtP . Constant_Value_nh4qnxlmtb , & rtP .
Constant1_Value_pxdhqqllht , & rtP . K3_Value , & rtP . uK2_Gain , & rtP .
uK1_Gain , & rtP . C1_Gain , & rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP .
Gain2_Gain , & rtP . beta_Gain , & rtP . Integrador_UpperSat , & rtP .
Integrador_LowerSat , & rtP . Saturador1_UpperSat , & rtP .
Saturador1_LowerSat , & rtP . Saturador2_UpperSat , & rtP .
Saturador2_LowerSat , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Saturation1_UpperSat , & rtP .
Saturation1_LowerSat , & rtP . Saturation2_UpperSat , & rtP .
Saturation2_LowerSat , & rtP . constant_Value , & rtP . constant1_Value , &
rtP . cp_Value , & rtP . cp1_Value , & rtP . ha_Value , & rtP . km_Value , &
rtP . rho_Value , & rtP . rho1_Value , & rtP . M_Value , & rtP .
constant_Value_dbb4dojqmp , & rtP . cp_Value_eh2zrr2jtp , & rtP .
cp1_Value_hzyk4t5t4c , & rtP . ha_Value_llewwjyayt , & rtP .
km_Value_feeasfdogm , & rtP . km1_Value , & rtP . rho_Value_k2fdqeovty , &
rtP . rho1_Value_oipnu5fd53 , & rtP . Gain_Gain_okzxc23qf2 , & rtP .
Filter_gainval , & rtP . Integrator_gainval , & rtP . Step_Y0 , & rtP .
Step_Y0_h2h1sloxcm , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) }
;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.1 , 15.0 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 2 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 4 , ( uint8_T ) 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 21 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 69 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1363514817U , 1699563187U , 4135759033U , 3873568147U } , ( NULL ) , 0 ,
( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo *
SistemaEstanques_PID_discreto_GetCAPIStaticMap ( void ) { return & mmiStatic
; }
#ifndef HOST_CAPI_BUILD
void SistemaEstanques_PID_discreto_InitializeDataMapInfo ( void ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void SistemaEstanques_PID_discreto_host_InitializeDataMapInfo (
SistemaEstanques_PID_discreto_host_DataMapInfo_T * dataMap , const char *
path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap (
dataMap -> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi ,
( NULL ) ) ; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
