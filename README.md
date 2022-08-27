# modelos-estanque
Datos, código y flujo de trabajo de los experimentos realizados

## Contenido

### Datos estanque
- En la carpeta "datos estanque" están los datos crudos correspondientes a la simulación del estanque, y tienen un tiempo de muestreo de 1 segundo. Particularmente se está experimentando con un control PID que actúa cada 10 segundos, a futuro se espera poder experimentar con distintas configuraciones de control PID tanto contínuo como discreto.

- En la subsección "Datos sin falla" están los datos del estanque operando con normalidad por 20 horas. 

- En la subsección "Datos con falla", todos los datos corresponden a la operación del estanque por 30 horas, de las cuales las primeras 10 corresponden a operación normal y el resto operación en falla. El tipo de falla es indicado en el nombre del archivo, siendo la falla incipiente la más interesante, dado que inicia de forma silenciosa y es cada vez más presente conforme pasa el tiempo.

- Los datos están en formato .csv y tienen los siguientes encabezados: "tiempo", "referencia", "hc", y "f_pid". Los datos de "referencia" corresponden a la referencia de nivel del estanque (i.e. el nivel al que se desea configurar el estanque, esta es cambiante en el tiempo cada 400 segundos), los datos de "hc" corresponden a la altura de agua en el estanque (en cm), y los datos de "f_pid" corresponden a la señal de control que se envía al actuador (bomba), en porcentaje de utilización, por lo que vive en el rango [0,100]. 

### Modelos Torch
- En esta carpeta se guardan los modelos ajustados y su respectiva documentación. Los modelos están en formato .pth y se pueden cargar en Torch para su uso.

### Outputs modelo
- En esta carpeta estan las salidas de las estimaciones del modelo y las señales de entrada para cada salida. Los archivos están tanto en formato .csv y .npy ordenados por subcarpeta y nombre.

### Notebooks
- En esta carpeta se encuentran los notebooks de Jupyter que contienen el código para entrenar los modelos y para correr los tests de la librería TSP-IT desde colab.

### TO DO:

- [ ] Justificar la elección de parámetros de entrada de la red neuronal (i.e. cantidad de autorregresores)
- [ ] Justificar la elección de la arquitectura de la red neuronal (i.e. cantidad de capas, cantidad de neuronas por capa, función de activación, etc.)
- [ ] Experimentar el test con combinaciones lineales de las señales de entrada.
- [ ] Desarrollar test de hipótesis que valide la experimentación y la robustez del método utilizado (p-valor, diferencia de medias, etc...)
 