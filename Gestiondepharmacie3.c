#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

	typedef struct
	{
			int id;
			int code;
			char nom[100];
			int quantite;
			float prix;
			float prix_ttc;
	}product;
	typedef struct
	{
		float total_prix;
		float moy_prix;
		float max_prix;
		float min_prix;
	}struct_stats;
	struct_stats stats;
	
	product *products;
	product temp;
	int size = 0;
	//stats.max_prix = 0;
	//stats.moy_prix =0;
	//stats.min_prix = 0;
	//stats.total_prix =0;
	int i =0;
	int j = 0;
	 int i;
         int totalquanty = 0;
         int prixquantity;
	 int quantite = 0;
         float ttl_prix = 0;
         float moy_price = 0;

    
               


	void printspaces(int start,int end)
	{
		while(start<end)
		{
			printf(" ");
			start++;
		}

	}
	int searchbycode(int code)
	{
		int i;
		i = 0;
		while(i <size)
		{
			if(products[i].code == code)
			{
				return i;
			}
			i++;
		}
		return  -1;
	}
	
		int searchbyquant(int quantite)
		{
			int i;
			i = 0;
			while(i<size)
			{
				if(products[i].quantite == quantite)
				{
					return i;
				}
				i++;
			}
			return -1;
		}

	
	//void update(product *p,int code,int size)
	//{
	//		int i;
	//	int index;
	//	i = 0;
	//	index = search(p,code,size);			
	//}
	void deletebycode(int code)
	{
		int searchcode;
		int i = 0;
		product *newp;
		newp = NULL;
		searchcode =  searchbycode(code);
		if(searchcode != -1)
		{
			newp = malloc(sizeof(product )*(size -1));
			while(i < size)
			{
				if(i != searchcode)
				{
					newp[i] = products[i];
				}
				i++;
			}
			size = size -1;
			products = newp;
		}
	}


	product* deletebyquantite(int quantite)
        {
                int searchquant;
                int i = 0;
                product *newp;
                newp = NULL;
                searchquant  = searchbyquant(quantite);
                if(searchquant != -1)
                {
                        newp = malloc(sizeof(product )*(size -1));
                        while(i<size)
                        {
                                if(i != searchquant)
                                {
                                        newp[i] = products[i];
                                }
                                i++;
                        }
                        size = size -1;
                        products =  newp;
                }
	}

	
	void printproduct()
	{
		int i;
		i = 0;
		char buffer[100];
		while(i<size)
		{
			if(i == 0)
			{
				printf("code");
				printspaces(4,10);
				printf("nom");
				printspaces(3,100);
				printf("quantite");
				printspaces(8,10);
				printf("prix\n\n");
			}
			printf("%d",products[i].code);
			printspaces(snprintf(buffer, 10, "%d", products[i].code),10);
			printf("%s",products[i].nom);
			printspaces(strlen(products[i].nom),100);
			printf("%d",products[i].quantite);
			printspaces(snprintf(buffer, 10, "%d", products[i].quantite),10);
			printf("%f\n",products[i].prix);
			i++;
		}

	}
	
	
	//operation  function 		
	int  printoneproduct(int code)
	{
		
		int i =0;
		printf("entrez le code a rechrcher");
		scanf("%d",&code);
		while(i < size)
	{
	
		char buffer[100];
			if(products[i].code == code)
			{
   			printf("%d",products[i].code);
                        //itoa(p[i].code,buffer,10);
                        printspaces(10,10);
                        printf("%s",products[i].nom);
                        printspaces(10,100);
                        printf("%d",products[i].quantite);
                        //itoa(p[i].quantite,buffer,10);
                        printspaces(snprintf(buffer, 10, "%d", products[i].quantite),10);
                        printf("%f\n",products[i].prix);
                        i++;

				return i;
				break;
			}
	}
		return -1;
	}

	void alimenterstock(int code,int quantity)
	{
		i = 0;
		while(i<size)
		{
		if(products[i].code == code)
		{
		products[i].quantite = products[i].quantite +quantity;
		}
		i++;
		}
		}
		void getstats()
		{
		int i;
		int totalquanty = 0;
		int prixquantity = 0;

		stats.total_prix = 0;
		stats.moy_prix = 0;
		stats.min_prix = 0;
		stats.max_prix = 0;
		if(size>0)
		{
			stats.min_prix = products[0].prix;
			stats.max_prix =products[0].prix;
		}
		while(i <size)
		{
			if(products[i].prix>stats.max_prix)
			{stats.max_prix = products[i].prix;
			}
			if(products[i].prix < stats.min_prix)
			{
				stats.min_prix =products[i].prix;
			}

			i++;

		}
		}
	void addproduct(int type)
	{	
		int i,j;
		int quantite;
		product *newproduct = NULL;
		newproduct = malloc(sizeof(product)*(size + type));
		i = 0;
		product new;
		int searchcode = -1;
		int searchindex = -1;
 
		prixquantity = 0;

		if(type == 0)
		{
			 printf("entrez le code du produit a modifier :\n");
			 scanf("%d",&searchcode);
               		 printf("entrez la quantite : \n");
			 scanf("%d",&quantite);
			 searchindex =	searchbycode(searchcode);
			 new.quantite = products[searchindex].quantite - quantite;
			 strcpy(new.nom,products[searchindex].nom);
			 new.prix = products[searchindex].prix;
			 new.code = searchcode;	

			totalquanty = totalquanty + quantite;	
			     if(products[searchindex].prix>stats.max_prix)
                        {stats.max_prix = products[searchindex].prix;
                        }
                        if(products[searchindex].prix < stats.min_prix)
                        {
                                stats.min_prix =products[searchindex].prix;
                        }
			if(stats.min_prix == 0)
			{
		 		stats.min_prix =products[searchindex].prix;		
			}
			stats.total_prix = stats.total_prix +(products[searchindex].prix*quantite);
			if(totalquanty>0)
			stats.moy_prix = stats.total_prix/(float)totalquanty;
		
			
			
			
		}
		else if(type == 1)
		{
		printf("entrez le code :\n");
		scanf("%d",&new.code);
		printf("entrez le nom : \n");
		scanf("%s",new.nom);
		printf("entrez la quantite : \n");
                scanf("%d",&new.quantite);
		printf("entrez le prix : \n");
                scanf("%f",&new.prix);
		}
		
		while(i < size)
		{
			newproduct[i] = products[i];
			newproduct[i].prix_ttc = newproduct[i].prix + ((newproduct[i].prix)*15/100);
			i++;
		}
		if(type == 1)
		{
		newproduct[i] = new;
		 //newproduct[i].prix_ttc = newproduct[i].prix + ((newproduct[i].prix)*15/100);
		 //printf("%f",newproduct[i].prix_ttc);
		size = size + 1;
		}
		else
		{
		searchindex = searchbycode(searchcode);
		if(searchindex != -1)
		{
		newproduct[searchindex] = new;
		}

		}

		products =  newproduct;
	}
	void swapnu()
	{
		i = 0;
		for(i =0;i<size;i++)
		{
		for(j =i+1 ; j<size ; j++)
		{
			if(products[i].prix > products[j].prix)
			{
			temp = products[i];
			products[i] =products[j];
			products[j] = temp;
			}
			}
		}

	}
	
	void swap()
	{
		  for(i =0;i < size;i++)
                    {
                     for(j =i+1;j <size ;j++ )
                      {
                        if(strcmp(products[i].nom ,products[j].nom) >0)
                             {
				temp = products[j]; 
				products[j] =products[i];
				products[i]= temp;
				}
                       }
                     }

	}
	
	product* manageproduct()
	{
		product* products;


	}

int main()
{

        int i = 0;
	int np;
	int j;
	int choice,choice1,choice2,code1;
	 time_t t = time(NULL);
	int code = 0;
	//products prod;
	//int quantite;
	 //float ttl_prix;
        //  float moy_price;
	//while(i<3)
        //{
       // products = addproduct(products, &size,1);
        //i++;
       //}
       // products = addproduct(products,&size,0);
       // products = deletebycode(products,code,&size);
        printproduct(products,size);
        //printf("%s",products[0].n
		int choix;
	do{	
	 printf("/================Application de Gestion de pharmacie ============================/\n");
	printf("Entre votre choix SVP ?\n");
	printf("           1-Ajouter un nouveau produit\n");
	printf("            2-Ajouter plusieurs nouveaux produits\n");
	printf("              3-Lister tous les produits\n");
	printf("               4-Acheter produit\n");
	 printf("                5-etat du stock:les  produit dont la quantite est moins de 3\n");
	printf("                  6-Rechercher les produits Par\n");
	printf("                      7-Alimenter le stock\n");
	printf("                        8- supprimer le produit par: \n");
	printf("                         9-Statistique de vente\n");
	printf("                            10-Exit\n");

		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
				 addproduct(1);	
				break;
			case 2:
				printf("entrer le nbr des produit souhaiter");
				scanf("%d",&np);
				 while(i<np)
        				{
					printf("entrez un produit :");
       					addproduct(1);
        					i++;
       					}
				break;
			case 3:
				printf("entrer votre choix :\n");
				printf("1- lister par odre alphabetique\n :");
				printf("2- lister par ordre decroissant de prix:\n");
				scanf("%d",&choice2);
				switch (choice2)
				{
					case 1:
						swap();
						printproduct();
						break;
					case 2:
						swapnu();
						printproduct();
						break;
				}
				break;
			case 4:
				addproduct(0);
				
				 //acheter(code,quantite);

				break;
			case 5:
			
                	i = 0;
              		char buffer[100];
                		while(i<size && products[i].quantite <= 3)
                		{
                        	if(i == 0)
                        	{
                                printf("code");
                                printspaces(4,10);
                                printf("nom");
                                printspaces(3,100);
                                printf("quantite");
                                printspaces(8,10);
                                printf("prix\n\n");
                       		}
                       		 printf("%d",products[i].code);
                       		 printspaces(snprintf(buffer, 10, "%d", products[i].code),10);
                       		 printf("%s",products[i].nom);
                       		 printspaces(strlen(products[i].nom),100);
                       		 printf("%d",products[i].quantite);
                        	printspaces(snprintf(buffer, 10, "%d", products[i].quantite),10);
                        	printf("%f\n",products[i].prix);
                        	i++;
                		}
				break;
			case 6:
				printf("rechercher par :\n");
				printf("1-par code\n");
				printf("2-par quatite :\n");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:
						i =0;
						printf("saisir votre code \n :");
						scanf("%d",&code1);
						 i = searchbycode(code1);
						 printf("%d",products[i].code);                
                                                  printspaces(10,10);
                                                   printf("%s",products[i].nom);
                                                   printspaces(10,100);
                                                     printf("%d",products[i].quantite);
                        			printspaces(10,10);
                       				 printf("%f\n",products[i].prix);
					break;
					case 2:
					i =0;
						 printf("saisir votre quantite \n :");
                                                 scanf("%d",&quantite);
                                                 i = searchbyquant(quantite);
                                                 printf("%d",products[i].code);
                                                 printspaces(10,10);
                                                   printf("%s",products[i].nom);
                                                   printspaces(10,100);
                                                     printf("%d",products[i].quantite);
                                                printspaces(10,10);
                                                 printf("%f\n",products[i].prix);

					break;
				}
				break;
			case 7:
				
				printf(" a ajoute :\n");
				printf("la quantite est :\n");
				scanf("%d",&quantite);
				printf("le code du produit est :");
				scanf("%d",&code);
				alimenterstock(code,quantite);	
        	                break;
	           	case 8: 
				printf("supprimer par  :\n");
				printf("1- par code : \n");
				printf("2- par quantite\n");
				printf("3- Exit :");
				scanf("%d",&choice); 
				
				switch(choice)
				{
					case 1:
						choice = 3;
						printf("entrez le code :\n");
						scanf("%d",&code);
						deletebycode(code);
						break;
					case 2:
						printf("entrer la quantite :\n");
						scanf("%d",&quantite);
						deletebyquantite(quantite);

						break;

				}
		

        	                break;
			case 9:
			        printf("%s",ctime(&t));
				 printf("total quantite vedu : %d\n",totalquanty);
                        	 printf(" total prix :%f\n",stats.total_prix);
                       		 printf(" prix moy des ventes %f\n",stats.moy_prix);

                         	 printf(" min prix :%f\n",stats.min_prix);
                                  printf(" le max : %f\n",stats.max_prix);


                	        break;
			case 10:
		        	  break;
		}
	}
	while(choix !=  10);

}
