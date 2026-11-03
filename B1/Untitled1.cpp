#include <iostream>
#include <string>
using namespace std;

class PhuongTien {
    private:
        int MaXe;                  
        string LoaiXe;             
        int GioVaoBai;                
        int ThoiGianDo;//gio           
        double PhiDo;//$           
        bool DangChiemCho=false;
    public:
        PhuongTien(){
            MaXe=0;
            LoaiXe="";
            GioVaoBai=0;
            ThoiGianDo=0;
            PhiDo=0;
            
        };
        PhuongTien(int MaXe, string LoaiXe, int GioVaoBai, int ThoiGianDo){
            this->MaXe=MaXe;
            this->LoaiXe=LoaiXe;
            this->GioVaoBai=GioVaoBai;
            this->ThoiGianDo=ThoiGianDo;
            PhiDo=0;
        };
        int GetMaXe(){return MaXe;}
        string GetLoaiXe(){return LoaiXe;}
        int GetGioVaoBai(){return GioVaoBai;}
        int GetThoiGianDo(){return ThoiGianDo;}
        double GetPhiDo(){return PhiDo;}
        bool GetDangChiemCho(){return DangChiemCho;}
        void SetMaXe(int ma){MaXe=ma;}
        void SetLoaiXe(string loai){LoaiXe=loai;}
        void SetGioVaoBai(int gio){GioVaoBai=gio;}
        void SetThoiGianDo(int thoiLuong){ThoiGianDo=thoiLuong;}
        void SetPhiDo(double phi){PhiDo=phi;}              
        void tinhPhiDoXe(){
            double phi1h;
            if(LoaiXe=="Car")  phi1h=6;
            else if(LoaiXe=="Motorcycle") phi1h=4;
            else if(LoaiXe=="Bicycle") phi1h=2;
            else return;
            double TongPhi=0;
            bool GioCaoDiem = (GioVaoBai >= 6 && GioVaoBai < 10)|| (GioVaoBai >= 15 && GioVaoBai < 19);
            if(GioCaoDiem){
                if(ThoiGianDo<=2) TongPhi+=phi1h*1.3*ThoiGianDo;
                else TongPhi+=phi1h*1.3*2;
                
            }
            else{
                if(ThoiGianDo<=2) TongPhi+=phi1h*0.95*ThoiGianDo;
                else TongPhi+=phi1h*0.95*2;
            }
            if(ThoiGianDo>2) TongPhi+=phi1h*0.9*(ThoiGianDo-2);
            PhiDo = TongPhi;
            cout << "Tong phi do xe: " << TongPhi<<endl;
        }
        void SetDangChiemCho(bool trangThai){DangChiemCho=trangThai;}    
        void hienThi(){
            cout"Ma xe: "<<MaXe<<" "<<"Loai xe: "<<LoaiXe<<" "<<"Phi do: "<<PhiDo<<endl;
        };
};
class BaiDoXe{
    private:
        int IdBaiDo;
        char size;
        PhuongTien pt1;
        PhuongTien pt2;
        PhuongTien pt3;
        bool haspt1;
        bool haspt2;
        bool haspt3;
    public:
        
        BaiDoXe(int id,char a){
            IdBaiDo=id;
            size=s;

            haspt1=false;
            haspt2=false;
            haspt3=false;

        }
        void GetIdBaiDo(){return idBaiDo;}
        void Gethaspt1(){return haspt1;}
        void Gethaspt2(){return haspt2;}
        void Gethaspt3(){return haspt3;}
        bool AddPhuongTien(const PhuongTien& v){
            if(size=='S'){
                if(haspt1==false){
                    pt1=v;
                    haspt1=true;
                    return true;
                }
            }
            else if(size=='M'){
                if(haspt1==false){
                    pt1=v;
                    haspt1=true;
                    return true;
                }
                else if(haspt2==false){
                    pt2=v;
                    haspt2=true;
                    return true;
                }
            }
            else if(size='L'){
                if(haspt1==false){
                    pt1=v;
                    haspt1=true;
                    return true;
                }
                else if(hapt2==false){
                    pt2=v;
                    haspt2=true;
                    return true;
                }
                else if(haspt3==false){
                    pt3=v;
                    haspt3=true;
                    return true;
                }
            }
            return false;
        }
        bool XoaPhuongTien(int vID){
            if(haspt1&&pt1.GetMaXe()==vID){
                haspt1=false;
                return true;
            }
            if(haspt2&&pt2.GetMaXe()==vID){
                haspt2=false;
                return true;
            }
            if(haspt3&&pt3.GetMaXe()==vID){
                haspt3=false;
                return true;
            }
            return false;
        }
        void HienThiBaiDoInFo(){
            cout<<"Id bai do la: "<<IdBaiDo<<endl;
            cout<<"Kich thuoc bai do la: "<<size<<endl;
            if(haspt1) pt1.hienthi();
            if(haspt2) pt2.hienthi();
            if(haspt3) pt3.hienthi();
            if(haspt1==false&&haspt2==false&&haspt3==false) cout<<"Bai trong"<<endl;
        }
};
class GiaoDien{
    private:
        BaiDoXe bai1;
        BaiDoXe bai2;
        BaiDoXe bai3;
        bool hasbai1;
        bool hasbai2;
        bool hasbai3;
    public:
        GiaoDien(){
            hasbai1=false;
            hasbai2=false;
            hasbai3=false;
        }
        void RunMenu(){
            int chon;
            do{
                cout<<"1.Tao bai do xe\n2.Them xe vao bai\n3.Xoa bai do xe\n4.Lay xe\n5.Liet ke cac bai do xe\n6.Hien thi xe theo bai\n7.Liet ke xe theo loai\n8.Tinh phi trung binh\n9.Thoat\n"
                cin>>chon;
                switch(chon){
                    case 1:{ 
                        int id;
                        char size;
                        cin>>id>>size;
                        if(!hasbai1){
                            bai1=BaiDoXe(id,size);
                            hasbai1=true;
                        }
                        else if(!hasbai2){
                            bai2=BaiDoXe(id,size);
                            hasbai2=true;
                        } 
                        else if(!hasbai3){
                            bai3=BaiDoXe(id,size);
                            hasbai3=true;
                        }
                        else break;

                            break;
                        }

                    case 2:{
                        if(!hasbai1&&!hasbai2&&!hasbai3) return;
                        int id,gio,time;
                        string loai;
                        cin>>id>>gio>>time>>loai;
                        PhuongTien a(id,loai,gio,time);
                        xe.tinhPhiDoXe();
                        bool b=false;
                        if(hasbai1) if(bai1.AddPhuongTien(a)) b=true;
                        if(!b&&hasbai2) if(bai2.AddPhuongTien(a)) b=true;
                        if(!b&&hasbai3) if(bai3.AddPhuongTien(a)) b=true;
                        if(b) cout<<"Thanh cong"<<endl;
                        else cout<<"bai full"<<endl;
                        break;
                    }
                    case 3:{
                        int id;
                        cin>>id;
                        if(hasbai1&&bai1.GetIdBaiDo()==id) hasbai1=false;
                        else if(hasbai2&&bai2.GetIdBaiDo()==id) hasbai2=false;
                        else if(hasbai3&&bai3.GetIdBaiDo()==id) hasbai3=false;
                        else break;
                        break;

                    }
                    case 4:{
                        int id;
                        cin>>id;
                        bool b=false;
                        if(hasbai1&&bai1.XoaPhuongTien(id)) b=true;
                        if(!b&&hasbai2&&bai2.XoaPhuongTien(id)) b=true;
                        if(!b&&hasbai3&&bai3.XoaPhuongTien(id)) b=true;
                        if(b) cout<<"Thanh cong"<<endl;
                        else cout<<"Khong tim thay xe";
                        break;
                    }
                    case 5:{ 
                        if(hasbai1) bai1.HienThiBaiDoInFo();
                        if(hasbai2) bai2.HienThiBaiDoInFo();
                        if(hasbai3) bai3.HienThiBaiDoInFo();
                        if(!hasbai1&&!hasbai2&&!hasbai3) cout<<"Chua co bai do"<<endl;                       
                        break;
                    }
                    case 6:{
                        int id;
                        cin>>id;
                        if(hasbai1&&bai1.GetIdBaiDo()==id) bai1.HienThiBaiDoInFo(); 
                        else if(hasbai2&&bai2.GetIdBaiDo()==id) bai2.HienThiBaiDoInFo();
                        else if(hasbai3&&bai3.GetIdBaiDo()==id) bai3.HienThiBaiDoInFo();
                        else cout<<"Khong tim thay"<<endl;
                        break;
                    }
                    default:return;
                }
            } while(chon !=9);
        }
};
int main(){
    GiaoDien a;
    a.RunMenu();
}
