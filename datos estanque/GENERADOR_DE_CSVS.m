%% ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ CUIDADO CON SOBREESCRIBIR LAS COSAS !!!!!!!!!!!!!! %%

TIME = f_pid.Time;
F_PID = f_pid.Data;
HC = Mesuared_hc.Data;
Referencia = REFERENCIA.Data;
prediction = PREDICTED_HC.Data;

headers = {'tiempo','referencia','hc','f_pid', 'predicted_hc'};
data = [TIME, Referencia, HC, F_PID, prediction];

DATOS_MODELO = [headers; num2cell(data)];

writecell(DATOS_MODELO, 'datos con falla/falla_fout_grave_t4s_long_v3.csv') %

