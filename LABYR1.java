import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;


class Main {

    static class Point {
        int x, y, length;

        Point(int x, int y, int length) {
            this.x = x;
            this.y = y;
            this.length = length;
        }
    }
    
    private static boolean isValid(int x, int y, int row, int col) {

        return x >= 0 && x < row && y >= 0 && y < col;
    }

    private static int[] X = {1, -1, 0, 0};
    private static int[] Y = {0, 0, 1, -1};

    static Point BFS(char[][] arr, int x, int y, int row, int col) {

        Queue<Point> qe = new ArrayDeque<>();
        qe.add(new Point(x, y, 0));
        boolean[][] visited = new boolean[row][col];
        Point to_return = new Point(0, 0, -1);
        while (!qe.isEmpty()) {

            int xx, yy;
            Point curr = qe.remove();
            visited[curr.x][curr.y] = true;
            if (curr.length > to_return.length) to_return = curr;
            for (int i = 0; i < 4; ++i) {

                xx = curr.x + X[i];
                yy = curr.y + Y[i];

                if (isValid(xx, yy, row, col) && arr[xx][yy] == '.' && !visited[xx][yy]) {
                    qe.add(new Point(xx, yy, curr.length + 1));
                }
            }
        }
        return to_return;
    }

    public static void main(String[] args) throws Exception {

        Reader cin = new Reader();
        PrintWriter pw = new PrintWriter(System.out);

        ////////////////////////////////////////////////////////////////////////////

        int T = cin.nextInt();
        while (T-- > 0) {

            int col = cin.nextInt();
            int row = cin.nextInt();
            char[][] arr = new char[row][];
            for (int i = 0; i < row; ++i) {
                arr[i] = cin.read_s().toCharArray();
            }
            Point calc = null;
            for (int i = 0; i < row; ++i) {

                for (int j = 0; j < col; ++j) {

                    if (arr[i][j] == '.') {
                        calc = BFS(arr, i, j, row, col);
                        break;
                    }
                }
                if (calc != null)
                    break;
            }
            calc = BFS(arr, calc.x, calc.y, row, col);
            pw.println("Maximum rope length is " + calc.length + ".");
        }

        ///////////////////////////////////////////////////////////////////////////////
        cin.close();
        pw.flush();
        pw.close();
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[1024]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public String read_s() throws IOException {
            byte[] buf = new byte[1024]; // line length
            int cnt = 0, c;

            while ((c = read()) != -1) {
                if (c == ' ' || c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
