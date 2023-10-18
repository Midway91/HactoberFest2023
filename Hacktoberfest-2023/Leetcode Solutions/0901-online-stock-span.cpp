class StockSpanner {
public:
    stack<pair<int, int>>st; // pair of{price, span} // code story with mik
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1; // currently span of price is 1 which is it self
        
        while(!st.empty() && st.top().first<=price)
        {
            span=span+st.top().second;
            st.pop();
        }
        st.push({price,span});
        
        return span; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */