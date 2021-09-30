import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import Axes3D

all_pts = np.loadtxt("pts.txt")
pts_raw = all_pts[:14, :]
pts_spl = all_pts[14:, :]


fig = plt.figure()
ax = fig.add_subplot(projection='3d')
ax.scatter(pts_raw[:, 0], pts_raw[:, 1], pts_raw[:, 2], color='r', marker='.')
ax.plot(pts_spl[:, 0], pts_spl[:, 1], pts_spl[:, 2], color='b', marker='*')

plt.show()
