import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

data = np.loadtxt("datos.dat")
fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = plt.plot([], [])

def init():
    ax.set_xlim(0, 1)
    ax.set_ylim(-0.5, 0.5)
    ax.set_xlabel("Posicion [m]")
    ax.set_ylabel("U")
    return ln,

def update(i):
    xdata.append(i)
    ydata.append(data[i*100])
    ln.set_data(xdata, ydata)
    return ln,

ani = FuncAnimation(fig, update, frames=np.arange(0, 1, 0.01), init_func=init, blit=True)
ani.save("fig.git")



