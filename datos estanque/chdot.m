%% ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ CUIDADO CON SOBREESCRIBIR LAS COSAS !!!!!!!!!!!!!! %%


prediction = hc_dot_hat.Data;

headers = {'predicted_hc'};
data = prediction;

DATOS_MODELO = [headers; num2cell(data)];

writecell(DATOS_MODELO, 'datos sin falla/low_pid_ref_fija_t5s_fuga_grave_noruido_hcdot.csv') %

