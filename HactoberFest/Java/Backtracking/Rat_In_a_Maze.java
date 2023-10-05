public class RatMaze {


    public static boolean isSafe(int i, int j, int maze[][], int n){
        
       if((i >= 0 && i < n) && (j >= 0 && j<n) && maze[i][j] == 1) 
            return true;

       return false;
    }

    public static boolean solve(int i, int j, int maze[][], int n, int ans[][]){
        if(i == n-1 && j == n-1 && maze[i][j] == 1){
            ans[i][j] = 1;
            return true;
        }

        if(isSafe(i, j, maze, n)){
            if(ans[i][j] == 1)
                return false;
            ans[i][j] = 1;

            if(solve(i+1, j, maze, n, ans))
                return true;
            if(solve(i, j+1, maze, n, ans))
                return true;
            ans[i][j] = 0;
            return false;
        }

        return false;

    }
    public static void main(String[] args) {
        

        int maze[][] = { { 1, 0, 0, 0 },
                         { 1, 1, 0, 1 },
                         { 0, 1, 0, 0 },
                         { 1, 1, 1, 1 } };
        int n = maze.length;

        int ans[][] = new int[n][n];

        System.out.println(solve(0, 0, maze, n, ans));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                System.out.print(ans[i][j]);
            System.out.println();
        }



        

    }
}
