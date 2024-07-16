# Bài 10 - DMA
1. Truy cập bộ nhớ trực tiếp DMA
DMA (Direct Memory Access) là một tính năng cho phép các thiết bị phần cứng trong hệ thống máy tính có thể truy cập bộ nhớ chính (RAM) mà không cần thông qua CPU. 
DMA có thể điều khiển data truyền từ:
- Bộ nhớ đến Peripheral 
- Ngược lại, Periph đến Bộ nhớ.
- Giữa 2 vùng nhớ.
- Không thông qua data bus của CPU. 
-> Giữ cho tài nguyên của CPU được rảnh rỗi cho các thao tác khác. Đồng thời tránh việc data nhận về từ ngoại vi bị mất mát.
