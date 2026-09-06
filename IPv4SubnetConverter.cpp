#include <iostream>
#include <math.h>
using namespace std;
void ipb(int ip[],int chart1[]){
    for(int i=0;i<4;i++){
        int k = ip[i];
        for(int j=0;j<8;j++){
            if(k>=chart1[j]){
                cout<<"1";
                k = k - chart1[j];
            }
            else{
                cout<<"0";
            }
        }
        cout<<".";
    }
}
void smb(int subm[],int chart1[],int &h,int &n){
    for(int i=0;i<4;i++){
        int k = subm[i];
        for(int j=0;j<8;j++){
            if(k>=chart1[j]){
                cout<<"1";
                k = k - chart1[j];
                n++;
            }
            else{
                cout<<"0";
                h++;
            }
        }
        cout<<".";
    }
}
int main() {
    while(1){
    int a,b,c,d,x,y,z,w,sb;
    char dot1,dot2,dot3;
    int h = 0,n = 0;
    cout<<"Enter your Ipv4 Address :";
    if(!(cin >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d) || 
        dot1 != '.' || dot2 != '.' || dot3 != '.'){
        cout<<"Invalid Inpt Format";
        return 1;
    }
    if(a<0 || a>255 || b<0 || b>255 || c<0 || c>255 || d<0 || d>255){
        cout<<"Invalid IPv4 Address";
        return 1;
        }
    if(a == 10 && b>=0 && b<=255 && c>=0 && c<=255 && d>=0 && d<=255){
        cout<<"Private Network in Class A";
        cout<<"\nSubnet Mask = 255.0.0.0";
        x = 255; y = 0; z = 0; w = 0;
    }
    else if(a == 172 && b>=16 && b<=31 && c>=0 && c<=255 && d>=0 && d<=255){
        cout<<"Private Network in Class B";
        cout<<"\nSubnet Mask = 255.255.0.0";
        x = 255; y = 255; z = 0; w = 0;
    }
    else if(a == 192 && b == 168 && c>=0 && c<=255 && d>=0 && d<=255){
        cout<<"Private Network in Class C";
        cout<<"\nSubnet Mask = 255.255.255.0";
        x = 255; y = 255; z = 255; w = 0;
    }
    else if(a == 127){
        cout<<"Loop Back Addresses";
        return 1;
    }    
    else if(a>=1 && a<=126){
        cout<<"Public Network";
        cout<<"\nClass A Network";
        cout<<"\nSubnet Mask = 255.0.0.0";
        x = 255; y = 0; z = 0; w = 0;
    }
    else if(a>=128 && a<=191){
        cout<<"Public Network";
        cout<<"\nClass B Network";
        cout<<"\nSubnet Mask = 255.255.0.0";
        x = 255; y = 255; z = 0; w = 0;
    }
    else if(a>=192 && a<=223){
        cout<<"Public Network";
        cout<<"\nClass C Network";
        cout<<"\nSubnet Mask = 255.255.255.0";
        x = 255; y = 255; z = 255; w = 0;
    }
    else if(a>=224 && a<=239){
        cout<<"Class D (Multicast)Network";
        return 0;
    }
    else if(a>=240 && a<=255){
        cout<<"Class E (Experimental/Research)Network";
        return 0;
    } 
    else{
        cout<<"Invalid IPv4 Address";
        return 1;
    }
    int ip[4] = {a,b,c,d};
    int subm[4] = {x,y,z,w};
    int chart1[8] = {128,64,32,16,8,4,2,1};
    int chart2[8] = {256,128,64,32,16,8,4,2};
    cout<<"\nBinary IPv4 Address = ";
    ipb(ip,chart1);
    cout<<"\nBinary Subnet Mask = ";
    smb(subm,chart1,h,n);
    cout<<"\nNo. of Network Bits = "<<n;
    cout<<"\nNo. of Host Bits = "<<h;
    int host = pow(2,h)-2;
    cout<<"\nTotal no.of Usable Ip Adresses in this network = "<<host;
    cout << "\n\nPress [y/n] to exit...";
    char choice;
        cout << "\nDo you want to exit? [y/n]: ";
        cin >> choice;
        if (choice == 'y') {
            cout << "Exiting program. Goodbye!\n";
            return 0;
        } 
        else if (choice == 'n') {
            cout << "\n----------------------------------------\n\n";
            
        } 
        else {
            cout << "Invalid choice! Continuing program...\n\n";
            
        }
    }
    return 0;
}