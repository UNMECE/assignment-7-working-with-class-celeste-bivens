#include <iostream>
#include <cmath>

class Electric_Field
{
    private: 
        double *E;
    public:
        Electric_Field()//default constructor
        { 
            E = new double[3];//array with 3 doubles (x, y, z)
            E[0] = 0.0;//initializing all components
            E[1] = 0.0;
            E[2] = 0.0;
            
            std::cout << "Default Constructor called" << std::endl;
        }

        Electric_Field(double x, double y, double z)
        { 
            E = new double[3];//array with 3 doubles (x, y, z)
            E[0] = x;//assigning x, y, and z.
            E[1] = y;
            E[2] = z;

            std::cout << "Constructor called" << std::endl;
        }
        
        void set_x(double x){//method: function for classes. Setting x variable.
            E[0] = x;
        }

        double get_x(){
            return E[0];
        }

        void set_y(double y){//method: function for classes. Setting y variable.
            E[1] = y;
        }

        double get_y(){
            return E[1];
        }

        void set_z(double z){//method: function for classes. Setting z variable.
            E[2] = z;
        }

        double get_z(){
            return E[2];
        }

        double calculate_magnitude()
        {
            auto x = get_x();
            auto y = get_y();
            auto z = get_z();
            double sum = (x*x + y*y + z*z);
            double mag = sqrt(sum);
            return mag;
        }

        void print()
        {
            std::cout << "Coordinate:(" << get_x() <<", " << get_y() <<", " << get_z() << ") "<< std::endl;
        }

        ~Electric_Field()//destructor
        {
            delete [] E;
            double *E = nullptr;
            std::cout << "Destructor called" << std::endl;
        }
};

class Magnetic_field
{
    private: 
        double *M;
        
    public: 
        Magnetic_field()//default constructor
        { 
            M = new double[3];//array with 3 doubles (x, y, z)
            
            M[0] = 0.0;//initializing all components
            M[1] = 0.0;
            M[2] = 0.0;
            
            std::cout << "Default Constructor called" << std::endl;
        }

        Magnetic_field(double x, double y, double z)
        { 
            M = new double[3];//array with 3 doubles (x, y, z)
            M[0] = x;//assigning x, y, and z.
            M[1] = y;
            M[2] = z;

            std::cout << "Constructor called" << std::endl;

        }
        //x-variable
        void set_x(double x){
            M[0] = x;
        }
        double get_x(){
            return M[0];
        }
        //y-variable
        void set_y(double y){
            M[1] = y;
        }
        double get_y(){
            return M[1];
        }
        //z-variable
        void set_z(double z){
            M[2] = z;
        }
        double get_z(){
            return M[2];
        }

        double calculate_magnitude()
        {
            auto x = get_x();
            auto y = get_y();
            auto z = get_z();
            double mag = sqrt(x*x + y*y + z*z);
            return mag;
        }
        
        double calculate_unit_vector_x()
        {
            auto x = get_x();
            auto y = get_y();
            auto z = get_z();
            double mag = calculate_magnitude();
            double unit_vector_x = (x/mag);
            if (mag = 0)//dividing by 0 is undefined
            {
                unit_vector_x = 0;
            }

            return unit_vector_x;
        }

        double calculate_unit_vector_y()
        {
            auto x = get_x();
            auto y = get_y();
            auto z = get_z();
            double mag = calculate_magnitude();
            double unit_vector_y = (y/mag);

            if (mag = 0)//dividing by 0 is undefined
            {
                unit_vector_y = 0;
            }
            return unit_vector_y;
        }

        double calculate_unit_vector_z()
        {
            auto x = get_x();
            auto y = get_y();
            auto z = get_z();
            double mag = calculate_magnitude();
            double unit_vector_z = (z/mag);

            if (mag = 0)//dividing by 0 is undefined
            {
                unit_vector_z = 0;
            }

            return unit_vector_z;
        }

        void print()
        {
            std::cout << "x: " << get_x() <<std::endl;
            std::cout << "y: " << get_y() <<std::endl;
            std::cout << "z: " << get_z() <<std::endl;        
        }

        ~Magnetic_field()//destructor
        {
            delete [] M;
            double *M = nullptr;
            std::cout << "Destructor called" << std::endl;
        }

};


int main(){
    //Electric Field
    Electric_Field defaultField;//Calling default constructor for the instance, "E_default"
    Electric_Field E_components(1e5, 10.9, 1.7e2);//Components for electric field passed into Electric field class.
    auto x1 = E_components.get_x();
    auto y1 = E_components.get_y();
    auto z1 = E_components.get_z();
    E_components.print();

    Electric_Field E_components2(13.5, 4e2, 7e3);//Calculating inner product of two coords
    auto x2 = E_components2.get_x();
    auto y2 = E_components2.get_y();
    auto z2 = E_components2.get_z();
    E_components2.print();

    auto inner_product = ((x1*x2) + (y1*y2) + (z1*z2));//Calculating inner product of the two coords.
    std::cout << "Inner product of both coordinates: " << inner_product << std::endl;

    auto E_mag = E_components.calculate_magnitude();
    std::cout << "Magnitude for 1st coordinate: " << E_mag << std::endl;
    auto E_mag2 = E_components2.calculate_magnitude();
    std::cout << "Magnitude for 2nd coordinate: " << E_mag2 << std::endl;
    std::cout << "---------------------------" << std::endl;
    
    //Magnetic field
    Magnetic_field M_components(1e5, 10.9, 1.7e2);//Creating instance, "M_components"
    M_components.print();
    auto unit_vector_x = M_components.calculate_unit_vector_x();
    auto unit_vector_y = M_components.calculate_unit_vector_y();
    auto unit_vector_z = M_components.calculate_unit_vector_z();

    std::cout << "Unit vector for magnetic field: (" << unit_vector_x << ", "<< unit_vector_y <<", " << unit_vector_z << ") " << std::endl;
    std::cout << "---------------------------" << std::endl;
    

    return 0;
}