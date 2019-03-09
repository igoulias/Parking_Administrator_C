/*Goulias Ioannis 1785 Gkourmpatshs Nikolaos 1791*/

#include <stdio.h>
#include <math.h>


int main (int argc , char* argv[]) {   
	char input;			/*dhlwsh k arxikopoihsh metablitwn*/
	int motor=0, car=0, truck=0, bus=0; 
	int in_hour,  in_min, out_hour, out_min, sum_hour, sum_min;
	sum_hour = 0;
	sum_min = 0;
	double debt = 0, round_debt = 0;
	int all_min_motor = 0, all_hour_motor = 0, avg_hour_motor = 0, avg_min_motor = 0;
	int all_min_car = 0, all_hour_car = 0, avg_hour_car = 0, avg_min_car = 0;
	int all_min_truck = 0, all_hour_truck = 0, avg_hour_truck = 0, avg_min_truck = 0;
	int all_min_bus = 0, all_hour_bus = 0, avg_hour_bus = 0, avg_min_bus = 0;
	double payment = 0;
	double all_payment = 0;
	double all_motor_debt = 0, all_car_debt = 0, all_truck_debt = 0, all_bus_debt = 0;
	double total_income = 0;
	double all_change = 0;
	int euros, twenties, fives, cents;
	do {
		printf("\nEnter vehicle type (M,m,C,c,T,t,B,b) or x to exit: ");		/*anagnwrish tupou oxhmatos*/
		scanf(" %c", &input);
		switch (input) {
			case 'M': { motor = motor + 1; break; }					/*katagrafh tupwn eisel8ontwn oxhmatwn*/
			case 'm': { motor = motor + 1; break; }
			case 'C': { car = car + 1; break; }
			case 'c': { car = car + 1; break; }
			case 'T': { truck = truck + 1; break; }
			case 't': { truck = truck + 1; break; }
			case 'B': { bus = bus + 1; break; }
			case 'b': { bus = bus + 1; break; }
			case 'x': { break; }
			default: {printf("\nError: Invalid vehicle type \"X\"!");}
		}
		
		if (input=='M'||input=='m'||input=='C'||input=='c'||input=='T'||input=='t'||input=='B'||input=='b') { 
			printf("\nEnter entry time (HH:MM, 24hr clock): ");					/*katagrafh oras eisodou*/
			scanf("%d:%d",&in_hour,&in_min);
			while(in_hour>23||in_hour<0||in_min>59||in_min<0) {
				printf("\nError: Hour must be between 0 and 23 and minute must be between 0 and 59!\n"); /*emfanish sfalmatos gia mh egkures times oras*/
				printf("\nEnter entry time (HH:MM, 24hr clock): ");
				scanf("%2d:%2d",&in_hour,&in_min);
			}
			
			printf("\nEnter exit time (HH:MM, 24hr clock): ");
			scanf("%d:%d",&out_hour,&out_min);				/*katagrafh oras eksodou*/
			while(out_hour>23||out_hour<0||out_min>59||out_min<0) {
				printf("\nError: Hour must be between 0 and 23 and minute must be between 0 and 59!\n"); /*emfanish sfalmatos gia mh egkures times oras*/
				printf("\nEnter exit time (HH:MM, 24hr clock): ");
				scanf("%2d:%2d",&out_hour,&out_min);
			}
			while(out_hour<in_hour||(out_hour==in_hour&&out_min<in_min)) {
				printf("\nError: Exit time must be after entrance time!\n"); /*emfanish sfalmatos gia ora eisodou > ora eksodou*/
				printf("\nEnter exit time (HH:MM, 24hr clock): ");
				scanf("%2d:%2d",&out_hour,&out_min);
			}
			if (input=='M'||input=='m') {		/*gia input motor*/
				if (in_hour==out_hour&&in_min==out_min) {	/* gia ora eisodou = ora eksodou dn xreiazetai plirwmh*/
					printf("No payment required.\n");
				}
				else {  
					sum_hour = out_hour * 60 - in_hour * 60;	/*gia mia posothta leptwn paramonhs sto parking upologizetai i sinoliki ora paramonhs se sinolika lepta*/
					sum_min = out_min - in_min;
					debt = (sum_hour + sum_min) * 0.75 / 60; /*ipologismos kai strogilopoihsh xreous gia ta sinolika lepta paramonhs sto parking*/
					round_debt = round(debt * 1000) / 10;
					round_debt = round(round_debt) / 100;
					printf("Please pay %.2lf euros: ", round_debt); /*emfanish xreous k katagrafh k strogilopoihsh plhrwteou posou*/
					scanf("%lf", &payment);
					payment = round(payment * 1000) / 10;
					payment = round(payment) / 100;
					all_payment = payment;			/*upologismos t sinolikou posou p plirwse o odhgos*/
					all_motor_debt = all_motor_debt + round_debt;		/*katagrafh sinolikou xreous mhxanwn pou eishl8an k strogilopoihsh*/
					all_motor_debt = round(all_motor_debt * 1000) / 10;
					all_motor_debt = round(all_motor_debt) / 100;
					while (payment < round_debt) {			/*otan o odhgos dwsei ligotera apo to xreos emfanizetai ews otou plhrw8ei to ypoloipomeno poso*/
						printf("\nPlease pay another %.2lf euros: " ,round_debt - payment);
						round_debt = round_debt - payment; 
						round_debt = round(round_debt * 1000) / 10;
						round_debt = round(round_debt) / 100;
						scanf("%lf", &payment);
						payment = round(payment * 1000) / 10;
						payment = round(payment) / 100;
						all_payment = all_payment + payment;		/*upologismos k strogilopoihsh t sinolikou posou p plirwse o odhgos*/
						all_payment = round(all_payment * 1000) / 10;
						all_payment = round(all_payment) / 100;
					}
					printf("\nYou paid %.2lf\n", all_payment);
					
					if (payment>round_debt) {	/*an o odhgos plirwsei perissotera apo to xreos tou*/
						printf("\nPlease take your change: ");
						all_change = payment - round_debt;	/*upologismos k strogilopoihsh restwn*/
						all_change = round(all_change * 1000) / 10; 
						euros = all_change / 100; /*upologismos twn restwn se eurw kai upodiaireseis analoga me to plhrwteo poso kai t upoloipo tou apo ka8e diairesh*/
						if (euros!=0){
							all_change = all_change - 100 * euros;	/*afairesh apo ta sinolika resta ta eurw*/
						}
						twenties = all_change / 20;
						if (twenties!=0){
							all_change = all_change - twenties * 20; /*afairesh apo ta resta ta 20lepta*/
						}
						fives = all_change / 5;
						if (fives != 0) {
							all_change = all_change - 5 * fives; /*afairesh apo ta  resta ta 5lepta*/
						}
						cents = all_change; /*ta upoloipa resta dinontai se cents*/
						  
						if (euros != 0) {
							printf("%d euros ", euros);
						}
						if (twenties != 0) {
							printf("%d twenties ", twenties);
						}
						if (fives != 0) {
							printf("%d fives ", fives);
						}
						if (cents != 0) {
							printf("%d cents ", cents); /*oi if mpainoun etsi oste se periptwsh p dn xrisimopoieitai kapoia ipodiairesh gia ta resta na mhn typwnetai kan*/
						}
						printf("\n");
					}
					
					all_min_motor = all_min_motor + sum_hour + sum_min;	/*upologismos sinolikhs wras paramonhs twn diaforwn mhxanwn se lepta*/
					
				}
			}
			else if (input=='C'||input=='c') {		/*gia input car*/
				if (in_hour==out_hour&&in_min==out_min) {
					printf("No payment required.\n"); /* gia ora eisodou = ora eksodou dn xreiazetai plirwmh*/
				}
				else {  
					sum_hour = out_hour * 60 - in_hour * 60;	/*gia mia posothta leptwn paramonhs sto parking upologizetai i sinoliki ora paramonhs se sinolika lepta*/
					sum_min = out_min - in_min;
					debt = (sum_hour + sum_min) * 2.25 / 60;	/*ipologismos kai strogilopoihsh xreous gia ta sinolika lepta paramonhs sto parking*/
					round_debt = round(debt * 1000) / 10;
					round_debt = round(round_debt) / 100;
					printf("Please pay %.2lf euros: ", round_debt); /*emfanish xreous k katagrafh k strogilopoihsh plhrwteou posou*/
					scanf("%lf", &payment);
					payment = round(payment * 1000) / 10;
					payment = round(payment)/100;
					all_payment = payment;	 	/*upologismos t sinolikou posou p plirwse o odhgos*/
					all_car_debt = all_car_debt + round_debt; /*katagrafh sinolikou xreous autokinhtwn pou eishl8an k strogilopoihsh*/
					all_car_debt = round(all_car_debt * 1000) / 10;
					all_car_debt = round(all_car_debt) / 100;
					while (payment < round_debt) { /*otan o odhgos dwsei ligotera apo to xreos emfanizetai ews otou plhrw8ei to ypoloipomeno poso*/
						printf("\nPlease pay another %.2lf euros: " ,round_debt - payment); 
						round_debt = round_debt - payment;
						round_debt = round(round_debt*1000)/10;
						round_debt = round(round_debt)/100;
						scanf("%lf", &payment);
						payment = round(payment * 1000) / 10;
						payment = round(payment) / 100;
						all_payment = all_payment + payment; /*upologismos k strogilopoihsh t sinolikou posou p plirwse o odhgos*/
						all_payment = round(all_payment * 1000) / 10; 
						all_payment = round(all_payment) / 100;
					}
					printf("\nYou paid %.2lf\n", all_payment);
					
					if (payment>round_debt) { /*an o odhgos plirwsei perissotera apo to xreos tou*/
						printf("\nPlease take your change: ");
						all_change = payment - round_debt; /*upologismos k strogilopoihsh restwn*/
						all_change = round(all_change * 1000) / 10;
						euros = all_change / 100;
						if (euros!=0){ /*upologismos twn restwn se eurw kai upodiaireseis analoga me to plhrwteo poso kai t upoloipo tou apo ka8e diairesh*/
							all_change = all_change - 100*euros; /*afairesh apo ta sinolika resta ta eurw*/
						}
						twenties = all_change / 20;
						if (twenties!=0){
							all_change = all_change - twenties * 20; /*afairesh apo ta  resta ta 20lepta*/
						}
						fives = all_change / 5;
						if (fives!=0) {
							all_change = all_change - 5 * fives; /*afairesh apo ta  resta ta 5lepta*/
						}
						cents = all_change; /*ta upoloipa resta dinontai se cents*/
						  
						if (euros != 0) {
							printf("%d euros ", euros);
						}
						if (twenties != 0) {
							printf("%d twenties ", twenties);
						}
						if (fives != 0) {
							printf("%d fives ", fives);
						}
						if (cents != 0) {
							printf("%d cents ", cents); /*oi if mpainoun etsi oste se periptwsh p dn xrisimopoieitai kapoia ipodiairesh gia ta resta na mhn typwnetai kan*/
						}
						printf("\n");
					}
					
					all_min_car = all_min_car + sum_hour + sum_min; /*upologismos sinolikhs wras paramonhs twn diaforwn autokinhtwn se lepta*/
					
				}
			}
			else if (input=='T'||input=='t') { /*gia input truck*/
				if (in_hour==out_hour&&in_min==out_min) {
					printf("No payment required.\n"); /* gia ora eisodou = ora eksodou dn xreiazetai plirwmh*/
				}
				else {  
					sum_hour = out_hour * 60 - in_hour * 60; /*gia mia posothta leptwn paramonhs sto parking upologizetai i sinoliki ora paramonhs se sinolika lepta*/
					sum_min = out_min - in_min;
					debt = (sum_hour + sum_min) * 5.40 / 60; /*ipologismos kai strogilopoihsh xreous gia ta sinolika lepta paramonhs sto parking*/
					round_debt = round(debt * 1000) / 10;
					round_debt = round_debt / 100;
					printf("Please pay %.2lf euros: ", round_debt); /*emfanish xreous k katagrafh k strogilopoihsh plhrwteou posou*/
					scanf("%lf", &payment);
					payment = round(payment * 1000) / 10;
					payment = round(payment)/100;
					all_payment = payment; 		/*upologismos t sinolikou posou p plirwse o odhgos*/
					all_truck_debt = all_truck_debt + round_debt; /*katagrafh sinolikou xreous fortigwn pou eishl8an k strogilopoihsh*/
					all_truck_debt = round(all_truck_debt * 1000) / 10;
					all_truck_debt = round(all_truck_debt) / 100;
					while (payment < round_debt) { /*otan o odhgos dwsei ligotera apo to xreos emfanizetai ews otou plhrw8ei to ypoloipomeno poso*/
						printf("\nPlease pay another %.2lf euros: " ,round_debt - payment);
						round_debt = round_debt - payment;
						round_debt = round(round_debt*1000)/10;
						round_debt = round(round_debt)/100;
						scanf("%lf", &payment);
						payment = round(payment * 1000) / 10;
						payment = round(payment) / 100;
						all_payment = all_payment + payment; /*upologismos k strogilopoihsh t sinolikou posou p plirwse o odhgos*/
						all_payment = round(all_payment * 1000) / 10;
						all_payment = round(all_payment) / 100;
					}
					printf("\nYou paid %.2lf\n", all_payment);
					
					if (payment>round_debt) { 	/*an o odhgos plirwsei perissotera apo to xreos tou*/
						printf("\nPlease take your change: ");
						all_change = payment - round_debt; /*upologismos k strogilopoihsh restwn*/
						all_change = round(all_change * 1000) / 10;
						euros = all_change / 100;
						if (euros!=0){ /*upologismos twn restwn se eurw kai upodiaireseis analoga me to plhrwteo poso kai t upoloipo tou apo ka8e diairesh*/
							all_change = all_change - 100*euros; /*afairesh apo ta sinolika resta ta eurw*/
						}
						twenties = all_change / 20;
						if (twenties!=0){
							all_change = all_change - twenties * 20; /*afairesh apo ta  resta ta 20lepta*/
						}
						fives = all_change / 5;
						if (fives!=0) {
							all_change = all_change - 5 * fives; /*afairesh apo ta  resta ta 5lepta*/
						}
						cents = all_change; /*ta upoloipa resta dinontai se cents*/
						  
						if (euros != 0) {
							printf("%d euros ", euros);
						}
						if (twenties != 0) {
							printf("%d twenties ", twenties);
						}
						if (fives != 0) {
							printf("%d fives ", fives);
						}
						if (cents != 0) { /*oi if mpainoun etsi oste se periptwsh p dn xrisimopoieitai kapoia ipodiairesh gia ta resta na mhn typwnetai kan*/
							printf("%d cents ", cents);
						}
						printf("\n");
					}
					
					all_min_truck = all_min_truck + sum_hour + sum_min; /*upologismos sinolikhs wras paramonhs twn diaforwn fortigwn se lepta*/
					
				}
			}
			else if (input=='B'||input=='b') { /*gia input bus*/
				if (in_hour==out_hour&&in_min==out_min) { 
					printf("No payment required.\n");	/* gia ora eisodou = ora eksodou dn xreiazetai plirwmh*/
				}
				else {  
					sum_hour = out_hour * 60 - in_hour * 60; /*gia mia posothta leptwn paramonhs sto parking upologizetai i sinoliki ora paramonhs se sinolika lepta*/
					sum_min = out_min - in_min;
					debt = (sum_hour + sum_min) * 8.60 / 60; /*ipologismos kai strogilopoihsh xreous gia ta sinolika lepta paramonhs sto parking*/
					round_debt = round(debt * 1000) / 10; 
					round_debt = round_debt / 100;
					printf("Please pay %.2lf euros: ", round_debt); /*emfanish xreous k katagrafh k strogilopoihsh plhrwteou posou*/
					scanf("%lf", &payment);
					payment = round(payment * 1000) / 10;
					payment = round(payment)/100;
					all_payment = payment;		/*upologismos t sinolikou posou p plirwse o odhgos*/
					all_bus_debt = all_bus_debt + round_debt; /*katagrafh sinolikou xreous lewforeiwn pou eishl8an k strogilopoihsh*/
					all_bus_debt = round(all_bus_debt * 1000) / 10;
					all_bus_debt = round(all_bus_debt) / 100;
					while (payment < round_debt) {  /*otan o odhgos dwsei ligotera apo to xreos emfanizetai ews otou plhrw8ei to ypoloipomeno poso*/
						printf("\nPlease pay another %.2lf euros: " ,round_debt - payment);
						round_debt = round_debt - payment;
						round_debt = round(round_debt * 1000) / 10;
						round_debt = round(round_debt)  /100;
						scanf("%lf", &payment);
						payment = round(payment * 1000) / 10;
						payment = round(payment) / 100;
						all_payment = all_payment + payment; /*upologismos k strogilopoihsh t sinolikou posou p plirwse o odhgos*/
						all_payment = round(all_payment * 1000) / 10;
						all_payment = round(all_payment) / 100;
					}
					printf("\nYou paid %.2lf\n", all_payment);
					
					if (payment>round_debt) {	/*an o odhgos plirwsei perissotera apo to xreos tou*/
						printf("\nPlease take your change: ");
						all_change = payment - round_debt;  /*upologismos k strogilopoihsh restwn*/
						all_change = round(all_change * 100);
						euros = all_change / 100;
						if (euros!=0){		/*upologismos twn restwn se eurw kai upodiaireseis analoga me to plhrwteo poso kai t upoloipo tou apo ka8e diairesh*/
							all_change = all_change - 100*euros; /*afairesh apo ta sinolika resta ta eurw*/
						}
						twenties = all_change / 20;
						if (twenties!=0){
							all_change = all_change - twenties * 20; /*afairesh apo ta  resta ta 20lepta*/
						}
						fives = all_change / 5;
						if (fives!=0) {
							all_change = all_change - 5 * fives; /*afairesh apo ta  resta ta 5lepta*/
						}
						cents = all_change; /*ta upoloipa resta dinontai se cents*/
						  
						if (euros != 0) {
							printf("%d euros ", euros);
						}
						if (twenties != 0) {
							printf("%d twenties ", twenties);
						}
						if (fives != 0) {
							printf("%d fives ", fives);
						}
						if (cents != 0) {
							printf("%d cents ", cents); /*oi if mpainoun etsi oste se periptwsh p dn xrisimopoieitai kapoia ipodiairesh gia ta resta na mhn typwnetai kan*/
						}
						printf("\n");
					}
					
					all_min_bus = all_min_bus + sum_hour + sum_min; /*upologismos sinolikhs wras paramonhs twn diaforwn lewforeiwn se lepta*/
					
				}
			}
		}
		
	}while(input!='x');
	
	if (input=='x') { /*gia x input*/
		if (motor!=0){ 
			all_hour_motor = all_min_motor / motor; /*ipologismos meshs wras k leptwn paramonhs twn mhxanwn sto parking*/
			avg_hour_motor = all_hour_motor / 60;
			avg_min_motor = all_hour_motor % 60;
		}
		if (car!=0) {
			all_hour_car = all_min_car / car; /*ipologismos meshs wras k leptwn paramonhs twn autokinhtwn sto parking*/
			avg_hour_car = all_hour_car / 60;
			avg_min_car = all_hour_car % 60;
		}
		if (truck!=0) {
			all_hour_truck = all_min_truck / truck; /*ipologismos meshs wras k leptwn paramonhs twn fortigwn sto parking*/
			avg_hour_truck = all_hour_truck / 60;
			avg_min_truck = all_hour_truck % 60;}
		if (bus!=0) {
			all_hour_bus = all_min_bus / bus; /*ipologismos meshs wras k leptwn paramonhs twn lewforeiwn sto parking*/
			avg_hour_bus = all_hour_bus / 60;
			avg_min_bus = all_hour_bus % 60;
		}
		total_income = all_motor_debt + all_car_debt + all_truck_debt + all_bus_debt; /*ipologismos k strogilopoihsh sinolikwn esodwn*/
		total_income = round(total_income * 100) / 100;
		
		/*tupwsh apotelesmatwn*/
		printf("MOTORCYCLES:\n");
		printf("\tNumber:%3d\n\tAverage parking time: %2d hrs %2d min\n\tIncome:%7.2lf\n", motor, avg_hour_motor, avg_min_motor, all_motor_debt);
		printf("\nCARS:\n");
		printf("\tNumber:%3d\n\tAverage parking time: %2d hrs %2d min\n\tIncome:%7.2lf\n", car, avg_hour_car, avg_min_car, all_car_debt);
		printf("\nTRUCKS:\n");
		printf("\tNumber:%3d\n\tAverage parking time: %2d hrs %2d min\n\tIncome:%7.2lf\n", truck, avg_hour_truck, avg_min_truck, all_truck_debt);
		printf("\nBUSES:\n");
		printf("\tNumber:%3d\n\tAverage parking time: %2d hrs %2d min\n\tIncome:%7.2lf\n", bus, avg_hour_bus, avg_min_bus, all_bus_debt);
		printf("\nTotal income:%7.2f\n",total_income);
		if (total_income!=0) { /* gia opoiodhpote eisodhma tupwnei ta ekatostiaia pososta eisodhmatos ka8e tupou oxhmatos*/
			printf("\t%.2lf%% is moto income\n",(all_motor_debt / total_income) * 100);
			printf("\t%.2lf%% is car income\n",(all_car_debt / total_income) * 100);
			printf("\t%.2lf%% is truck income\n",(all_truck_debt / total_income) * 100);
			printf("\t%.2lf%% is bus income\n",(all_bus_debt / total_income) * 100);
		}
		else { /*gia mhdeniko eisodhma tupwnei mhdenika pososta*/
			printf ("\t0.00%% is moto income\n"); 
			printf ("\t0.00%% is car income\n");
			printf ("\t0.00%% is truck income\n");
			printf ("\t0.00%% is bus income\n");
		}
	}
	
	return (0);
}