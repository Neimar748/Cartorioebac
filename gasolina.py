

import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("gasolina.csv")

data["dia"] = pd.to_datetime(data["dia"])

data = data.sort_values(by="dia")

plt.plot(data["dia"], data["venda"], marker="o", linestyle="-")

plt.xlabel("Dia")
plt.ylabel("Preço")

plt.title('Preço da Gasolina ao Longo do Tempo')

plt.show()

plt.savefig('grafico_gasolina.png')

