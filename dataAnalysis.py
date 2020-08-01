import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data.csv")
print(data.columns)
plt.plot(data["Time"], data["Sick"])
plt.plot(data["Time"], data["Susceptible"])
plt.plot(data["Time"], data["Immune"])
plt.plot(data["Time"], data["Dead"])

#plt.plot(data["Time"])
plt.show()