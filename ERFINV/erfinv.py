from time import time
from scipy.special import erfinv

print(erfinv(0.5))
print(erfinv(0.9))
print(erfinv(0.99))

start = time()

N = int(1E6)
for i in range(N):
  erfinv(i/N)

print(str(time()-start) + " sec")
