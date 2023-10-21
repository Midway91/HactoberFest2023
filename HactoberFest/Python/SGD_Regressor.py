# Simple class implementing Stochastic gradient descent Regressor
import numpy as np

class SGDRegressor:
    
    def __init__(self,learning_rate=0.01, epochs=100):
        self.coef_ = None
        self.intercept_ = None
        self.lr = learning_rate
        self.epochs = epochs    
    
    def fit(self,X_train, y_train):
        #initialize the m=0 and all betas=1
        self.intercept_ = 0
        self.coef_ = np.ones(X_train.shape[1])
        
        for i in range(self.epochs):
            for j in range(X_train.shape[0]):
                idx = np.random.randint(0,X_train.shape[0])
                yhat = np.dot(X_train[idx],self.coef_) + self.intercept_
                
                intercept_der = -2 * (y_train[idx]-yhat)
                self.intercept_ = self.intercept_ - (self.lr*intercept_der)
            
                coef_der = -2 * ((y_train[idx] - yhat)*X_train[idx])
                self.coef_ = self.coef_ - (self.lr*coef_der)
        print(self.intercept_, self.coef_)      
                
            
    def predict(self, X_test):
        return np.dot(X_test, self.coef_) + self.intercept_
        

# # And to use the SGD regressor, You can uncomment the following code and run it
# # And you have to import/download a dataset (Down there I have used a dataset and train test splited it)
# # X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=0.2, random_state=2) --> like this
# # to make an object of SGDRegressor calss 
# sgd = SGDRegressor(learning_rate=0.01, epochs=150)
# # to fit the model 
# sgd.fit(X_train, y_train)
# # to predict the unknown values 
# sgd.predict(X_test)