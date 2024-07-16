Bài 9: ADC (Analog to Digital Converter)

Giới thiệu: Tín hiệu thực tế luôn ở dạng tương tự, để vi điều khiển có thể hiểu được thì cần phải chuyển đổi tín hiệu tương tự thành tín hiệu số
1. Chuyển đổi tương tự - số: 
    - Phương pháp: Từ 1 tín hiệu analog, mã hóa nó thành 1 mã nhị phân (dữ liệu số). Ví dụ dùng 3 bit để mã hóa 1 tín hiệu analog thành 1 tín hiệu digital có 8 mức.
    - Độ phân giải: Như vậy có thể hiểu dùng càng nhiều bit thì tín hiệu digital có độ phân giải càng cao (high resolution). Ví dụ 8 bit sẽ có 2^8 mức. Độ phân giải càng cao càng tốn nhiều không gian lưu trữ.
    - Tần số lấy mẫu: Thời gian lấy mẫu càng ngắn, mức độ tái tạo tín hiệu càng cao
    - Công thức: Tần số lấy mẫu = 1/(Thời gian lấy mẫu + Thời gian chuyển đổi)
    - Tần số lấy mẫu nên lớn hơn tần số của tín hiệu ít nhất 2 lần để đảm bảo độ chính xác

2. ADC trên STM32
STM32F103C8 có 2 bộ ADC đó là ADC1 và ADC2 với nhiều mode hoạt động
Kết quả chuyển đổi được lưu trữ trong thanh ghi 16 bit. 
    - Độ phân giải 12 bit.
    - Có các ngắt hỗ trợ.
    - Có thể điều khiển hoạt động ADC bằng xung Trigger.
    - Thời gian chuyển đổi nhanh : 1us tại tần số 65Mhz.
Có bộ DMA giúp tăng tốc độ xử lí.

3. Cấu hình ADC
    - Các bộ ADC được cấp xung từ RCC APB2, để bộ ADC hoạt động cần cấp xung cho cả ADC để tạo tần số lấy mẫu tín hiệu và cấp xung cho GPIO của Port ngõ vào.
    - ADC hỗ trợ rất nhiều kênh, mỗi kênh lấy tín hiệu từ các chân GPIO của các Port và từ các chân khác. Các chân GPIO dùng làm ngõ vào cho ADC sẽ được cấu hình Mode AIN.(Analogue Input).


void RCC_Config(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_ADC1|RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
}

void GPIO_Config(){
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

