%% ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ CUIDADO CON SOBREESCRIBIR LAS COSAS !!!!!!!!!!!!!! %%

TIME = f_pid.Time;
F_PID = f_pid.Data;
HC = Mesuared_hc.Data;
Referencia = REFERENCIA.Data;
%prediction = hc_dot_hat.Data;

%headers = ['tiempo','referencia','hc','f_pid'];%, 'predicted_hc'};
data = [TIME, Referencia, HC, F_PID];%, prediction];

DATOS_MODELO = data;

%writematrix(DATOS_MODELO, 'datos con falla/25s/10m1/10m1_1b_st25s.csv') ;
writematrix(DATOS_MODELO, 'datos sin falla/5s/train_2_st25s.csv') ;

%10m1_10b_st5s

%  o10m4_fp10a_st18s_long