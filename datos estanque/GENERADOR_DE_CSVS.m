%% ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ CUIDADO CON SOBREESCRIBIR LAS COSAS !!!!!!!!!!!!!! %%

TIME = f_pid.Time;
F_PID = f_pid.Data;
HC = Mesuared_hc.Data;
Referencia = REFERENCIA.Data;
headers = {'tiempo','referencia','hc','f_pid'};
data = [TIME, Referencia, HC, F_PID];

DATOS_MODELO = [headers; num2cell(data)];

writecell(DATOS_MODELO, 'datos con falla/data_falla_incipiente_bomba_v2.csv') %