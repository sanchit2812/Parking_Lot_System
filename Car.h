//Class Declaration for Car
class Car{

    private:
    string regno;

    public:
//setRegNo is a function to set the reg_no
        void setRegNo(string s) {
            regno = s;
        }
//getRegNo is a function to get the reg_no
        string getRegNo(){
            return regno;
        }
};
