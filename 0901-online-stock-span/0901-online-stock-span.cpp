class StockSpanner {
    private:
    vector<int> ans;
    stack<pair<int,int>> stock; //{price,span}
    

public:
    StockSpanner() {  
    }
    
    int next(int price) {
        int span = 1;
        
        while(!stock.empty() && stock.top().first<=price){
            span += stock.top().second;
            stock.pop();
        }
        stock.push({price, span});
        ans.push_back(span);
        
        return span;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */