import java.util.List;
import java.util.ArrayList;

public class Graph {
   private String id;
   private List<Graph> adjacences;

   public Graph(String id) {
      this.id = id;
      this.adjacences = new ArrayList<Graph>();
   }

   public String getId() {
      return id;
   }

   public void setId(String id) {
      this.id = id;
   }

   public void addAdjacence(Graph adjacence) {
      if (!this.adjacences.contains(adjacence)) {
         this.adjacences.add(adjacence);
      }
   }

   public void removeAdjacence(Graph adjacence) {
      if (!this.adjacences.contains(adjacence)) {
         this.adjacences.remove(adjacence);
      }
   }

   public Boolean hasAdjacence(Graph adjacence) {
      return this.adjacences.contains(adjacence);
   }

   @Override
   public int hashCode() {
      final int prime = 31;
      int result = 1;
      result = prime * result + ((id == null) ? 0 : id.hashCode());
      return result;
   }

   @Override
   public boolean equals(Object obj) {
      if (this == obj)
         return true;
      if (obj == null)
         return false;
      if (getClass() != obj.getClass())
         return false;
      Graph other = (Graph) obj;
      if (id == null) {
         if (other.id != null)
            return false;
      } else if (!id.equals(other.id))
         return false;
      return true;
   }
}
