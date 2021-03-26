#include <iostream>

using namespace std;

class Restaurant{
	public:
		string food[5] = {0};
		virtual void menu()=0;	//pure virtual function
};

class Italian_Restaurant : public Restaurant{
	private:
		int size = 5;
		void menu(){
			food[1] = "Pizza";
			food[2] = "Eggplant Parmigiana";
			food[3] = "Chicken Parmigiana";
			food[4] = "Baked Ziti";
			food[5] = "Penne Primavera";
		}
	public:
		void getMenu(){
			menu();
			for(int i=0; i<size; i++){
				cout<<food[i]<<endl;
			}	
		}
};

class Greek_Restaurant : public Restaurant{
	public:
		int size = 5;
		void menu(){
			food[1] = "Greek Salad";
			food[2] = "Greek Yogurt";
			food[3] = "Mediterranean Bowl";
			food[4] = "Lentil Soup";
			food[5] = "Baklava";
		}
		void getMenu(){
			menu();
			for(int i=0; i<size; i++){
				cout<<food[i]<<endl;
			}	
		}
};

class Chinese_Restaurant : public Restaurant{
	public:
		int size = 5;
		void menu(){
			food[1] = "Sesame Chicken";
			food[2] = "Chicken Lo Mein";
			food[3] = "Beef Lo Mein";
			food[4] = "Tso Chicken";
			food[5] = "Chicken Friend Rice";
		}
		void getMenu(){
			menu();
			for(int i=0; i<size; i++){
				cout<<food[i]<<endl;
			}	
		}
};

template <typename T>
class Reader_Robot{
	T restaurant;
	T info;
	public:
		int size = 5;
		Reader_Robot(T r){
			restaurant = r;
			restaurant += "_Restaurant";
		}
		void read(){
			if (restaurant == "Italian_Restaurant")
			{
				Italian_Restaurant im;
				im.getMenu();
			}
			if (restaurant == "Greek_Restaurant")
			{
				Greek_Restaurant gr;
				gr.getMenu();
			}
			if (restaurant == "Chinese_Restaurant")
			{
				Chinese_Restaurant cr;
				cr.getMenu();
			}
		}
};

int main(){
	cout<<"Read menu from Italian Restaurant, Greek Restaurant, or Chinese Restaurant? "<<endl;
	string answer;
	cin >> answer;
	Reader_Robot<string> resta(answer);
	resta.read();
	
}
