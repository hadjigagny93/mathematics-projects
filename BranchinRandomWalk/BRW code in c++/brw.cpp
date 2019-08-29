
#include "brw.hpp"

std::mt19937 G(time(NULL));




void BRW::ajoute_enfant(){
	

	Point haut(_x+1,_y+1);
	Point bas(_x+1,_y-1);
	std::bernoulli_distribution ber1(0.5);
	std::uniform_int_distribution<int> uniform(1,2);
	if( ber1(G) == 1){ 
		if( uniform(G) == 1) { ensemble.resize(1); ensemble[0] = haut; }
		else { ensemble.resize(1); ensemble[0] = bas;}
		
	}	
	else { ensemble.resize(2); ensemble[0] = haut; ensemble[1] = bas;}
	
}

void BRW::generation(int N, std::ostream & file){
		int n =0;
		
		int taille = 0;
		
		std::vector<Point> newgeneration;
		
		ajoute_enfant();
		newgeneration.resize(ensemble.size());
		newgeneration = ensemble;
		
		int augmente = 0;
		
		for( int time = 2; time <= N; time++){
				newgeneration.clear();
				
				
				for( int enfant = 0; enfant < ensemble.size(); enfant++){
						
						BRW parent((ensemble[enfant]));
						parent.ajoute_enfant();
					
						
						for(int nouveau = 0; nouveau < parent.ens().size(); nouveau++ ){
							newgeneration.push_back(parent.ens()[nouveau]);	
							file << parent.ens()[nouveau].x() << " " << parent.ens()[nouveau].y() << " "<< std::endl << parent.x() <<" "<< parent.y()<< std::endl << std::endl;
							std::cout << parent.ens()[nouveau].x() << " " << parent.ens()[nouveau].y() << " "<< std::endl << parent.x() <<" "<< parent.y()<< std::endl << std::endl;
							}
						
		
						
					
					
					
				}
				
			ensemble.resize(newgeneration.size());
			ensemble = newgeneration;
			//condition2();
			
			
			
			
		
		
		}	
}		
void BRW::condition(){
for(int i =0; i < ensemble.size(); i++){
		for(int j=0; j < 4; j++){
			if( j + i + 1 < ensemble.size()) {
				if( ensemble[i].y() == ensemble[j + i +1].y()){
					ensemble.erase( ensemble.begin() + j+i+1);
				}
			}
			if ( j -i -1 > 0 & j - i - 1 < ensemble.size()){
				 if( ensemble[i].y() == ensemble[j - i -1].y()){ 
					 ensemble.erase( ensemble.begin() + j-i-1);
					}
				
			}
		}
	
}	
	
	



}

void BRW::condition2(){
for(int i =0; i < ensemble.size(); i++){
		for(int j=i+1; j < ensemble.size(); j++){
			if( ensemble[i].y() == ensemble[j].y()){
				ensemble.erase(ensemble.begin() + j);
				}
			
	
}	
	
	



}
}
		

	
	



		
		
		
		
		
		
		
		
		
		
		
		
		
		



				






