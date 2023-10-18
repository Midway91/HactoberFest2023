package poo;

import java.util.Scanner;

public class ThreeDimensionalArray {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String[] soccerLeagues = new String[3];
		String[][] clubs = new String[3][3];
		String[][][] players = new String[3][3][1];

		for (int i = 0; i < soccerLeagues.length; i++) {
			System.out.println("Enter the league's name " + (i + 1) + " : ");
			soccerLeagues[i] = scanner.nextLine();

			for (int j = 0; j < clubs[i].length; j++) {
				System.out.println("Enter the club's name " + (j + 1) + " - league " + (i+1));
				clubs[i][j] = scanner.nextLine();
				
				for (int k = 0; k < players[i][j].length; k++) {
					System.out.println("Enter the player's name: " + (k + 1));
					players[i][j][k] = scanner.nextLine();
				}
				
			}
			
		}
		
		for (int i = 0; i < soccerLeagues.length; i++) {
			System.out.println("League: " + soccerLeagues[i]);

			for (int j = 0; j < clubs[i].length; j++) {
				System.out.println("Club: " + clubs[i][j]);
				
				for (int k = 0; k < players[i][j].length; k++) {
					System.out.println("Player: " + players[i][j][k]);
				}
			}

		}
	}

}
