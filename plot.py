import imageio
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("datos.dat")


images = []

x = np.arange(0,1.01, 0.01)

for i in range(200):
    
    img = plt.figure()
    plt.title("Tiempo: " + str(0.01*i) + " segundos.")
    plt.plot(x, data[i])
    plt.grid()
    plt.xlabel("Posicion [metros]")
    plt.ylabel("U")
    plt.savefig("figura"+str(i)+".png")
    plt.close(img)

with imageio.get_writer('anim.gif', mode='I') as writer:
    for i in range(200):
        image = imageio.imread("figura"+str(i)+".png")
        writer.append_data(image)