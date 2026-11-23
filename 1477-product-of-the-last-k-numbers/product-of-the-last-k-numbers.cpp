class ProductOfNumbers {
public:
    vector<int> preprod;
    ProductOfNumbers() {
        preprod.push_back(1);
    }

    void add(int num) {
        int n=preprod.size();
        if(num==0){
            preprod.clear();
            preprod.push_back(1);
        }
        else{
            preprod.push_back(preprod.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=preprod.size();
        if(k>=n){
            return 0;
        }
        return preprod[n-1]/preprod[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */