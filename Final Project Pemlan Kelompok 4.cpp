#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>

struct Item{
	char barang[100];
	char jenis[50];
	char alamat[100];
	int stok;
	int harga;
};

void printChar(char ch, int n){
	while(n--){
		putchar(ch);
		}
}

void masuk()
{
	int i,member=0,simpanindex;
	char nama[20],akun;
	char password[25], passtemp[25], listpassword[20][20],listusername[20][20];
	bool ceksymbol, cekbesar,cekkecil,cekangka,cekuser;
	
	    system("COLOR 03");
	    printf("\n\n\t\t");
		printChar('_',30);
		printf("\n\n\t\t\tSELAMAT DATANG\n\t\t");
		printChar('_',30);
		printf("\n\n\t\t APAKAH ANDA SUDAH MEMILIKI AKUN ?\n\n");
		printf("\t\t	 [Y]	[T]\n\t\t\t      ");
		scanf("%s",&akun);
          if(akun=='t'||akun=='T')
          { 
		    system("CLS");
			printf("\n\n\t\t");
			printChar('_',30);
			printf("\n\n\t\t\t   REGISTRASI\n\t\t");
			printChar('_',30);
			printf("\n\n\t\tUsername : ");
			scanf("%s", nama);
			while (8>7)
			{
				printf("\t\tPassword : ");
				scanf("%s", password);
				if (strlen(password)>8)
				{
					cekangka =false;
					cekbesar =false;
					cekkecil =false;
					ceksymbol =false;
					
					for (i = 0; i< strlen(password); i++)
						{
							if (password[i]>= 45 && password[i]<= 57)
								{cekangka=true;}
							else if (password[i]>= 65 && password[i]<=90)
								{cekbesar=true;}
							else if (password[i]>=97 && password[i]<= 122)
								{cekkecil=true;}
							else 
								{ceksymbol=true;}
						}
					if(cekangka==true && cekbesar == true && cekkecil == true && ceksymbol ==true)
					{ }
					else
					 {
						printf("paswword harus terdiri dari angka besar & kecil, huruf, dan symbol\n");
						continue;
					 } 
						 strcpy(passtemp,password);
						 if (password == strrev(passtemp))
					 {
					 	printf("password anda palindrome");
					 	continue;
					 }
					 break;
				}
					else
					{
						printf("password anda kurang dari 8 digit");
						continue;	
					}
			}
			strcpy(listusername[member],nama);
			strcpy(listpassword[member], password);
			printf("\n\t\tBerhasil dibuat");
			getch();system("CLS");
			
			login:
			while (0<1)
			{
				printf("\n\n\t\t");
				printChar('_',30);
				printf("\n\n\t\t\t    LOGIN\n\t\t");
				printChar('_',30);
				printf("\n\n\t\tUsername : ");
				scanf("%s", nama);
				
				cekuser = false;
				
				for (i=0; listusername[i][i] != '\0'; i++)
				{
					if(strcmp(listusername[i],nama)==0)
					{
						simpanindex =i;
						cekuser=true;
					}
				} 
				if (cekuser == false)
				{
					printf("Username tidak ada\n");
					continue;
				}
				printf("\t\tPassword : ");
				scanf("%s",password);
				if ((password)==0)
				{
					continue;
				}
				else { }
				printf("\n\n\t\t");
				printf("Now Loading");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				system("CLS"); 
				break;
				
			}
			
		}
		if (akun == 'y' || akun == 'Y')
		{
			system("CLS"); goto login;
		}
		
          
}


void title(){
	system("CLS");
	system("COLOR 03");
	printf("\n\n\t");
	printChar('_',64);
	printf("\n\n\t\t\t\tOnline Shop");
	printf("\n\n\t");
	printChar('_',64);
}

void tambah(){
	title();
	FILE *pfile = fopen("inputdata.txt", "a+");
	if(pfile == NULL){
		printf("\n\n\t\tERROR!!\n");
	}
	Item i;
	printf("\n\n\t\t\t======= INPUT  DATA =======\n\n");
	printf("\n\t\t\tNama Barang     : ");
    gets(i.barang);
    printf("\t\t\tJenis Barang    : ");
    gets(i.jenis);
    printf("\t\t\tStok Barang     : ");
    scanf("%d", &i.stok);
    printf("\t\t\tHarga Barang    : ");
    scanf("%d", &i.harga);
    
    fwrite(&i,sizeof(i),1,pfile);
    printf("\n\n\t\t\tBARANG BERHASIL DITAMBAHKAN\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(pfile);
    return;
}

void display(){
	title();
	FILE *pfile = fopen("inputdata.txt", "r");
	if(pfile == NULL){
		printf("\n\n\t\tERROR!!");
	}
	Item i;
	printf("\n\n\t\t\t====DISPLAY DATA BARANG====\n\n");

    while((fread(&i,sizeof(i),1,pfile))==1)
    {
        printf("\n\n\t\tNama Barang   : %s", i.barang);
        printf("\n\t\tJenis Barang  : %s", i.jenis);
        printf("\n\t\tStok Barang   : %d", i.stok);
        printf("\n\t\tHarga Barang  : %d\n\n\t", i.harga);
        printChar('-',64);
    }

    fclose(pfile);
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void hapusbarang(){
	title();
	FILE *pfile = fopen("inputdata.txt", "r");
	FILE *temp = fopen("temp.txt", "w");
	Item i, tempInput;
	int pilih, flag = 0;
	
	if (pfile == NULL || temp == NULL){
		printf("\n\t\t\tERROR!!\n\n");
	}
	
	printf("\n\n\t\t\t=====HAPUS DATA BARANG=====\n\n");
	printf("\n\t\t\tMasukan Nama Barang : ");
	gets(tempInput.barang);
	
	while(fread(&i, sizeof(i), 1, pfile)==1){
		if(strcmp(i.barang,tempInput.barang)==0){
			flag++;
			printf("\n\t\t\tNama Barang  : %s", i.barang);
        	printf("\n\t\t\tJenis Barang : %s", i.jenis);
        	printf("\n\t\t\tStok Barang  : %d", i.stok);     
			printf("\n\t\t\tHarga Barang : %d", i.harga);
			printf("\n\n\t\t\tYakin barang di hapus?\n");
			printf("\t\t\t1. Iya\n");
			printf("\t\t\t2. Tidak\n");
			printf("\t\t\tMasukan Pilihan :");
			scanf("%d", &pilih);
			if(pilih == 1){
				printf("\n\n\t\t\tInformasi barang telah dihapus!\n\n");
			}
			else if(pilih == 2){
				fwrite(&i, sizeof(i), 1, temp);
			}
			else{
				printf("\n\n\t\tPILIHAN TIDAK ADA!!");
				fwrite(&i, sizeof(i), 1, temp);
			}
		}
		else{
			fwrite(&i, sizeof(i), 1, temp);
		}
	}
	
	fclose(pfile);
	fclose(temp);
	
	remove("inputdata.txt");
	rename("temp.txt", "inputdata.txt");
	
	if(flag == 0){
		printf("\n\n\t\tBarang tidak ditemukan");
	}
	printf("\n\n\t\t\tEnter any keys to continue........");
}

void search(){
	title();
	FILE *pfile = fopen("inputdata.txt", "r");
	Item i;
	int pilih, flag = 0;
	char barang[50];
	if (pfile == NULL){
		printf("\n\n\t\tERROR!!\n");
	}
    printf("\n\n\t\t\t======= Cari Barang =======\n");
    printf("\n\n\t\t\tNama barang : ");
    gets(barang);
        while (fread(&i, sizeof(i), 1, pfile) == 1)
        {
            if (strcmp(i.barang, barang) == 0)
            {
                flag++;
				printf("\n\t\t\tNama Barang  : %s", i.barang);
        		printf("\n\t\t\tJenis Barang : %s", i.jenis);
        		printf("\n\t\t\tStok Barang  : %d", i.stok);     
				printf("\n\t\t\tHarga Barang : %d", i.harga);       
			}
        }
        if (flag == 0)
        {
            printf("\n\t\t\tBARANG TIDAK ADA");
        }
	
	fclose(pfile);
	printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void beli(){
	title();
	printf("\n\t");
	printChar('_',64);
	FILE *pfile = fopen("inputdata.txt", "r+");
	FILE *temp = fopen("temp.txt", "w+");
	Item i, tempInput;
	int flag = 0;
	if (pfile == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    printf("\n\n\t\t\t======== TRANSAKSI ========\n");
    printf("\n\t\t\tNama Barang : ");
    gets(tempInput.barang);
	while (fread(&i, sizeof(i), 1, pfile) == 1){
        	if (strcmp(i.barang, tempInput.barang) == 0){
				flag++;
				printf("\n\n\t\t\tMasukan alamat pengiriman        : ");
				gets(i.alamat);
				printf("\n\n\t\t\tMasukan jumlah yang ingin dibeli : ");
				scanf("%d", &tempInput.stok);
				
				if (i.stok < tempInput.stok){
					printf("\n\n\t\t\tStok tidak ada");
					fwrite(&i, sizeof(i), 1, temp);
				}
				else{
					i.stok -= tempInput.stok;
						printf("\n\n\t\t\t");
				        printChar('_',40);
				        printf("\n\n\t\t\tPESANAN ANDA\n\t\t\t");
				    	printChar('_',40);
						printf("\n\t\t\tNama Barang  : %s", tempInput.barang);
						printf("\n\t\t\tKategori     : %s", i.jenis);
						printf("\n\t\t\tJumlah       : %d", tempInput.stok);
				        printf("\n\t\t\tHarga Barang : %d", i.harga);
				        printf("\n\t\t\tAlamat       : %s", i.alamat);
				        printf("\n\t\t\t");
				        printChar('_',40);
				        getch();
					printf("\n\n\t\t\tBARANG BERHASIL DIBELI!!");
					fwrite(&i, sizeof(i), 1, temp);
				}
			}
			else{
				fwrite(&i, sizeof(i), 1, temp);
			}
		}
	if (flag == 0)
    {
        printf("\n\t\t\tBarang tidak ditemukan");
    }
    fclose(pfile);
    fclose(temp);

    remove("Inputdata.txt");
    rename("temp.txt", "inputdata.txt");

    printf("\n\n\t\t\tEnter any keys to continue.......");
    
}

void update(){
	title();
	FILE *pfile = fopen("inputdata.txt", "r");
	FILE *temp = fopen("temp.txt", "w");
	Item i, tempInput;
	int flag = 0;
	if (pfile == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    printf("\n\n\t\t\t======= Update Stok =======\n");

    printf("\n\t\t\tNama Barang : ");
    gets(tempInput.barang);
	while (fread(&i, sizeof(i), 1, pfile) == 1){
        	if (strcmp(i.barang, tempInput.barang) == 0){
				flag++;
				printf("\n\n\t\t\tMasukan jumlah stok : ");
				scanf("%d", &tempInput.stok);
				
					i.stok += tempInput.stok;
					fwrite(&i, sizeof(i), 1, temp);
					printf("\n\n\t\t\tStok berhasil di update");
				
			}
			else{
				fwrite(&i, sizeof(i), 1, temp);
			}
		}
	if (flag == 0)
    {
        printf("\n\t\t\tBarang tidak ditemukan");
    }
    fclose(pfile);
    fclose(temp);

    remove("Inputdata.txt");
    rename("temp.txt", "inputdata.txt");

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void menupenjual(){
	title();
	char ch;
    puts("\n\t\t\t\t1. Input Data\n");
    puts("\n\t\t\t\t2. Display Data\n");
    puts("\n\t\t\t\t3. Hapus Data\n");
    puts("\n\t\t\t\t4. Search Data\n");
    puts("\n\t\t\t\t5. Update Stok\n");
    puts("\n\t\t\t\t6. Kembali");
    printf("\n\t");
    printChar('_',64);
    puts("\n\t\t\t\tMasukan pilihan");
    fflush(stdin);
    ch=getch();
    switch (ch){
    	case '1':
    		tambah();
		    break;
        case '2':
        	display();
            break;
        case '3':
        	hapusbarang();
        	break;
        case '4':
        	search();
        	break;
        case '5':
        	update();
        	break;
        case '6':
        	return;
        	break;
	}
}

void menupembeli(){
	title();
    puts("\n\t\t\t\t1. Display Data\n");
    puts("\n\t\t\t\t2. Beli Barang\n");
    puts("\n\t\t\t\t3. Kembali");
    printf("\n\t");
    printChar('_',64);
    puts("\n\t\t\t\tMasukan pilihan");
    switch (getch()){
    	case '1':
    		display();
		    break;
        case '2':
        	beli();
            break;
        case '3':
        	return;
        	break;
	}
}

int main(){
	
	SetConsoleTitle("Project UAS Kelompok 4");
	system("cls");
	masuk();
   do{
   	system("cls");
   	title();
    puts("\n\n\t\t\t\t1. Penjual\n");
    puts("\n\t\t\t\t2. Pembeli\n");
    puts("\n\t\t\t\t3. Keluar");
    printf("\n\t");
    printChar('_',64);
    puts("\n\t\t\t\tMasukan pilihan");
    switch (getch()){
    	case '1':
		menupenjual(); 
            break;
        case '2':
		menupembeli();            
			break;
        case '3':
        	return 0;
            break;
        default:
            printf("\n\t\tNo Action Detected");
            printf("\n\t\tPress Any Key\n\n\n");
			getch();
        	system("pause");
        	
	}
   }
   while(getch()!=27);
   return 0;
}

