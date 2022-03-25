class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
       // strings to extract real and img parts
        string real1, img1, real2, img2;
        // ints to store integer values of real and img parts
        int r1, i1, r2, i2;
        int len1 = 0, len2 = 0;
        
        //extracting real part from num1
        while(num1[len1] != '+'){
            real1 += num1[len1];
            len1++;
        }
        
        len1++;
        
        //extracting img part from num1
        while(num1[len1] != 'i'){
            img1 += num1[len1];
            len1++;
        }
        
        //extracting real part from num2
        while(num2[len2] != '+'){
            real2 += num2[len2];
            len2++;
        }
        
        len2++;
        
        //extracting img part from num2
        while(num2[len2] != 'i'){
            img2 += num2[len2];
            len2++;
        }
        
        // converting strings of real and img parts to int
        // for multiplication purpose using stringstream
        stringstream s1, s2, s3, s4;
        s1<<real1;
        s1>>r1;
        s2<<img1;
        s2>>i1;
        s3<<real2;
        s3>>r2;
        s4<<img2;
        s4>>i2;
        
        // returning the resultant multiplication
        return to_string(r1*r2 - i1*i2) + '+' + to_string(r1*i2 + i1*r2) + 'i';
    }
};