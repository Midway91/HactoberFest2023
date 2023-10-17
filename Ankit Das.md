("git add <file>..." Bowling Game in Java)

import java.util.*; 



public class Bowling {

    HashMap<String, Integer> players;

    Bowling() {

        players = new HashMap<String, Integer>();

    }

    public void addPlayer(String name, int p) {

        players.put(name, p);

    }

    //your code goes here

    public void getWinner() {

        System.out.println(players.entrySet()

        .stream().max((entry1, entry2) -> entry1.getValue() > entry2.getValue() ? 1 : -1).get().getKey());

    }

}



public class Program {

    public static void main(String[ ] args) {

        Bowling game = new Bowling();

        Scanner sc = new Scanner(System.in);



        for(int i=0;i<3;i++) {

            String input = sc.nextLine();

            String[] values = input.split(" ");

            String name = values[0];

            int points = Integer.parseInt(values[1]);

            game.addPlayer(name, points);

        }

        game.getWinner();

    }

}
