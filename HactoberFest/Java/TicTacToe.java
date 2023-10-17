import java.sql.SQLOutput;
import java.util.*;

public class TicTacToe {
    static ArrayList<Integer> playerPos=new ArrayList<Integer>();
    static ArrayList<Integer> cpuPos=new ArrayList<Integer>();

    public static void main(String[] args) {
        char[][] gameBoard = {{' ','|',' ','|',' '},
                {'-','+','-','+','-'},
                {' ','|',' ','|',' '},
                {'-','+','-','+','-'},
                {' ','|',' ','|',' '}};
        printGameBoard(gameBoard);
        Scanner in=new Scanner(System.in);
        while(true)
        {
            System.out.println("Enter Placement(1-9)");
            int pos=in.nextInt();
            while(playerPos.contains(playerPos)||cpuPos.contains(playerPos)) {
                System.out.println("Enter correctly");
                pos=in.nextInt();
            }
            System.out.println(pos);
            placePiece(gameBoard,pos,"player");
            Random r=new Random();
            int cpuPos=r.nextInt(9)+1;
            placePiece(gameBoard,cpuPos,"cpu");
            printGameBoard(gameBoard);
            String result= checkW();
            System.out.println(result);
        }
    }

    public static void printGameBoard(char[][]gameBoard)
    {
        for(char[]row:gameBoard)
        {
            for(char c:row) {
                System.out.print(c);
            }
            System.out.println();

        }
    }

    public static void placePiece(char [][] gameBoard,int pos,String user)
    {
        char symbol='X';
        if(user.equals("player"))
        {
            symbol='X';
            playerPos.add(pos);
        }
        if(user.equals("cpu"))
        {
            symbol='O';
            cpuPos.add(pos);
        }
        switch (pos)
        {
            case 1:
            gameBoard[0][0]=symbol;
            break;
            case 2:
            gameBoard[0][2]=symbol;
            break;
            case 3:
            gameBoard[0][4]=symbol;
            break;
            case 4:
            gameBoard[2][0]=symbol;
            break;
            case 5:
            gameBoard[2][2]=symbol;
            break;
            case 6:
            gameBoard[2][4]=symbol;
            break;
            case 7:
            gameBoard[4][0]=symbol;
            break;
            case 8:
            gameBoard[4][2]=symbol;
            break;
            case 9:
            gameBoard[4][4]=symbol;
            break;

        }
    }

    public static String checkW()
    {
        List topRow= Arrays.asList(1,2,3);
        List midRow= Arrays.asList(4,5,6);
        List botRow= Arrays.asList(7,8,9);

        List topCol= Arrays.asList(1,4,7);
        List midCol= Arrays.asList(2,5,9);
        List botCol= Arrays.asList(3,6,9);

        List ld= Arrays.asList(1,5,9);
        List rd= Arrays.asList(7,5,3);

        List<List> winning=new ArrayList<List>();
        winning.add(topRow);
        winning.add(midRow);
        winning.add(botRow);

        winning.add(topCol);
        winning.add(midCol);
        winning.add(botCol);

        winning.add(ld);
        winning.add(rd);

        for(List l:winning)
        {
            if(playerPos.containsAll(l))
            {
                return"Congratulations You Won!";
 
             }
            else if(cpuPos.containsAll(l))
            {
                return "CPU Wins!";

            }
            else if(playerPos.size()+cpuPos.size()==9)
            {
                return "Tie!";
                
            }
        }
        return "";

    }
}
