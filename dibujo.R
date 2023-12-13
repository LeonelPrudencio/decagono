# Lee los puntos desde el archivo
puntos <- read.table("puntos_decagono.txt", sep = ",", header = FALSE)
colnames(puntos) <- c("X", "Y")

# Crea un gráfico de dispersión con la biblioteca base
plot(puntos$X, puntos$Y, main = "Decágono", xlab = "Coordenada X", ylab = "Coordenada Y", pch = 16, col = "blue")

# Conecta los puntos para formar un decágono
lines(c(puntos$X, puntos$X[1]), c(puntos$Y, puntos$Y[1]), type = "l", col = "red")

# Agrega las coordenadas encima de cada punto
text(puntos$X, puntos$Y, labels = sprintf("(%0.2f, %0.2f)", puntos$X, puntos$Y), pos = 3, col = "black")

# Agrega la etiqueta "Decágono" al gráfico
legend("topleft", legend = "Decágono", col = "red", lty = 1, cex = 0.8)

print("Gráfico generado exitosamente")