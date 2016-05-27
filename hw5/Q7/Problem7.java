import java.io.*;
import java.util.*;



public class Problem7 {

        public static void main(String[] args) {
                int N = 5105039;
                String path = "../web-Google.txt";
                //String path = "./test.txt";
                File file = new File(path);
                String[] data = new String[N];

                //ArrayList<String>[] adj = new ArrayList[N];
                ArrayList<String>[] adj = new ArrayList[N];
                String[] id = new String[N];

				int size_nodes = 0;
                try {
                        BufferedReader br = new BufferedReader(new FileReader(file));
                        String line;
                        int n = -1;
						String lastNode = "----";
                        while ((line = br.readLine()) != null) {
                                String[] parts = line.split("\t");
								String source = parts[0];
								String destination = parts[1];

								if (source.equals(lastNode)) {
									adj[n].add(destination);
								}
								else {
									n++;
									id[n] = source;
									adj[n] = new ArrayList();
									adj[n].add(destination);
									lastNode = source;
									size_nodes++;
								}
                        }
                        br.close();
                } catch (IOException e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                }

                HashSet<String>[] adj_set = new HashSet[size_nodes];

				for (int i = 0; i < size_nodes; i++) {
					//System.out.print(id[i] + " -->");
					int size_des_link_1 = adj[i].size();
					adj_set[i] = new HashSet<String>();
					for (int j = 0; j < size_des_link_1; j++) {
						String u = adj[i].get(j);
						adj_set[i].add(u);
						//System.out.print(" " + u); // u = node link 1
						int index_u = -1;
						
						// find Index u
						for (int k = 0; k < size_nodes; k++) {
							if (id[k].equals(u)) {
								index_u = k;
								break;
							}
						}

						if (index_u == -1) continue;

						int size_des_link_2 = adj[index_u].size();
						for (int k = 0; k < size_des_link_2; k++) {
							String v = adj[index_u].get(k);
							//System.out.print(" " + v); // v = node link 2
							adj_set[i].add(v);
							
						}
						
						
					}
					//System.out.println("");
				}

				for (int i = 0; i < size_nodes; i++) {
					System.out.print(id[i] + " --> ");
					System.out.println(adj_set[i]);
				}
        }
}


