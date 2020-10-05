int nums[40000]; 

class ProductOfNumbers {
    int i = 0;
    int product = 1;
    int lastZero = -1;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num==0) {
            num = 1;//we will not change product
            lastZero = i;
            product = 1;
        }
        product*=num;
        nums[i++] = product;
    }
    
    int getProduct(int k) {
        if (lastZero>=i-k) return 0;
        if (i==k) return product;
        return product/nums[i-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
