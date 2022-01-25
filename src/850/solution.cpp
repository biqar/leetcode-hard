//
// Created by Islam, Abdullah Al Raqibul on 01/25/22.
//

class Solution {
public int rectangleArea(int[][] rectangles) {
    int N = rectangles.length;
    Set<Integer> Xvals = new HashSet();
    Set<Integer> Yvals = new HashSet();

    for (int[] rec: rectangles) {
      Xvals.add(rec[0]);
      Xvals.add(rec[2]);
      Yvals.add(rec[1]);
      Yvals.add(rec[3]);
    }

    Integer[] imapx = Xvals.toArray(new Integer[0]);
    Arrays.sort(imapx);
    Integer[] imapy = Yvals.toArray(new Integer[0]);
    Arrays.sort(imapy);

    Map<Integer, Integer> mapx = new HashMap();
    Map<Integer, Integer> mapy = new HashMap();
    for (int i = 0; i < imapx.length; ++i)
      mapx.put(imapx[i], i);
    for (int i = 0; i < imapy.length; ++i)
      mapy.put(imapy[i], i);

    // System.out.println("imapx.length=" + imapx.length + " imapy.length=" + imapy.length);
    boolean[][] grid = new boolean[imapx.length][imapy.length];
    for (int[] rec: rectangles) {
      for (int x = mapx.get(rec[0]); x < mapx.get(rec[2]); x+=1) {
        for (int y = mapy.get(rec[1]); y < mapy.get(rec[3]); y+=1) {
          // System.out.println("x=" + x + " y=" + y);
          grid[x][y] = true;
        }
      }
    }

    long ans = 0;
    for (int x = 0; x < grid.length; x+=1) {
      for (int y = 0; y < grid[0].length; y+=1) {
        if (grid[x][y]) {
          ans += (long) (imapx[x+1] - imapx[x]) * (imapy[y+1] - imapy[y]);
          // System.out.println("x=" + x + " imapx[x+1]=" + imapx[x+1] + " imapx[x]=" + imapx[x]);
          // System.out.println("y=" + y + " imapy[y+1]=" + imapy[y+1] + " imapy[y]=" + imapy[y]);
          // System.out.println("");
        }
      }
    }

    ans %= 1_000_000_007;
    return (int) ans;
  }
}