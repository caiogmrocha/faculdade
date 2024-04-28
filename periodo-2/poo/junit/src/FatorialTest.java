import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class FatorialTest {
    @Test
    public void testFatorial() {
        assertEquals(120, Fatorial.fatorial(5));
    }
}
