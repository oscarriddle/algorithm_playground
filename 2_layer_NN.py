'''
This is a extremely simple 2-layer-NN.

Input size is (64,1000), output size is (64,10)
Activation Function Type: Sigmoid
BackProp Algorithm: SGD
Weight Regularization: No
Batch Normalization: No

'''
import numpy as np
from numpy.random import randn


N, D_in, H, D_out = 64, 1000, 100, 10
x, y = randn(N, D_in), randn(N, D_out)
w1, w2 = randn(D_in, H), randn(H, D_out)

for t in range(3000):
    h = 1 / (1 + np.exp(-x.dot(w1)))
    y_pred = h.dot(w2)
    loss = np.sqrt(np.square(y_pred - y).sum())


    grad_y_pred = 2.0 * (y_pred - y)
    grad_w2 = h.T.dot(grad_y_pred)
    grad_h = grad_y_pred.dot(w2.T)
    grad_w1 = x.T.dot(grad_h * h * (1-h)) # * operator multiple same positions

    w1 -= 1e-4 * grad_w1
    w2 -= 1e-4 * grad_w2

    print (t, loss)
print x.shape, w1.shape, h.shape, w2.shape, y_pred.shape
print grad_y_pred.shape, grad_w2.shape, grad_h.shape, grad_w1.shape
########################################################

# X = np.array([[0,0,1], [0,1,1], [1,0,1], [1,1,1]])
# Y = np.array([[0,1,1,0]]).T

# syn0 = 2*np.random.random((3,4)) - 1
# syn1 = 2*np.random.random((4,1)) - 1

# for j in xrange(60000):
#     l1 = 1 / (1 + np.exp(-(np.dot(X,syn0))))
#     l2 = 1 / (1 + np.exp(-(np.dot(l1,syn1))))
#     l2_delta = (Y-l2)*(l2*(1-l2))
#     l1_delta = l2_delta.dot(syn1.T) * (l1 * (1-l1))
#     syn1 += l1.T.dot(l2_delta)
#     syn0 += X.T.dot(l1_delta)

#     print (j, Y-l2)
