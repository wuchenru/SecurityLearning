# Memory Diagram

| High Memory (Large Addresses)       |
+--------------------+                
|      Stack         | (Local vars, grows downwards)
|        ↓           |
+--------------------+  
|       Heap         | (Dynamic memory, grows upwards)
|        ↑           |
+--------------------+
|    Static Data     | (Global and static variables)
+--------------------+
|      Code          | (Program instructions)
| Low Memory (Small Addresses)        |

| 0xFFFF_FFFF (High Memory, ~4GB on 32-bit systems) |
+--------------------+
|      Stack         | (e.g., 0xFFFF_E000 to 0xFFFF_FFFF)
|        ↓           |
+--------------------+  
|       Heap         | (e.g., 0x1000_0000 to 0xFFFF_DFFF)
|        ↑           |
+--------------------+
|    Static Data     | (e.g., 0x000F_F000 to 0x0FFF_FFFF)
+--------------------+
|      Code          | (e.g., 0x0000_0000 to 0x000F_EFFF)
| 0x0000_0000 (Low Memory)                          |
