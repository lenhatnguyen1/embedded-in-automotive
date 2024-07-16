Bài 8: Ngắt ngoài, Ngắt Timer, Ngắt truyền thông
1. Ngắt ngoài:
    - Xác định chân ngắt ngoài -> cấu hình GPIO
    - Bật clock tương ứng, ngoài ra cần bật thêm AFIO
    - Xác định ngắt mức cao, thấp, rising, falling

Ví dụ:
void GPIO_Config(){
GPIO_InitTypeDef GPIOInitStruct;
    //
    GPIOInitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIOInitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIOInitStruct);
}

Cấu hình EXTI
    - Hàm GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource) cấu hình chân ở chế độ sử dụng - ngắt ngoài:
    - GPIO_PortSource: Chọn Port để sử dụng làm nguồn cho ngắt ngoài.
    - GPIO_PinSource: Chọn Pin để cấu hình.
    - Các tham số ngắt ngoài được cấu hình trong Struct EXTI_InitTypeDef, gồm:
    - EXTI_Line: Chọn line ngắt.
    - EXTI_Mode: Chọn Mode cho ngắt là Ngắt(thực thi hàm ngắt) hay Sự kiện(Không thực thi)
    - EXTI_Trigger: Cấu hình cạnh ngắt.
    - EXTI_LineCmd: Cho phép ngắt ở Line đã cấu hình.

