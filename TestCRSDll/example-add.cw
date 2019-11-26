# 示例：波形相加
GAmp = 200;

f = 20;
length = 400;  # 不要超过 4x10^6
w1 = Sin(f, L=length);
w2 = Sin(2*f, L=length, ph0=0.5);

w3 = w1 + w2;
s1 = SEQ([w3(1, T)]);

OUT1 = s1;
OUT2 = s1;