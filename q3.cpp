#include <iostream>
#include <vector>
#define SIZE 50
#define debug(x) {cout << #x << " : " << x << endl ;}
using namespace std;

int main(){
    
    int a[SIZE] = {396, 549, 22, 819, 611, 972, 730, 638, 978, 342, 566, 514, 752, 
                   871, 911, 172, 488, 542, 482, 974, 210, 474, 66, 387, 1, 872, 799, 
                   262, 567, 113, 578, 308, 813, 515, 716, 905, 434, 101, 632, 450, 
                   74, 254, 1000, 780, 633, 496, 513, 772, 925, 746};

    int signs[SIZE] = {0};
    int dp[SIZE] = {1};
    
    for(int i=1;i<SIZE;i++){
        
        for(int j = i-1; j>=0; j--){            
            int sign = signs[j];
            
            if( (sign == 0) || ( (sign < 0) && (a[i] - a[j] > 0) ) || 
                    ( (sign > 0) && (a[i] - a[j] < 0) ) ){
                dp[i] = dp[j] + 1;
                
                signs[i] = a[i] - a[j];
                break;
            }
        }
    }

    cout << dp[SIZE-1] << endl;
    return 0;
}