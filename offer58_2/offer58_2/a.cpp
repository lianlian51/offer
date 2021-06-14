#include<reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define LCD_data P0
sbit SDA = P3 ^ 5;
sbit SCL = P3 ^ 4;//24C08���ƿ�����
sbit LCD_RS = P3 ^ 3; //�Ĵ���ѡ������
sbit LCD_RW = P3 ^ 6; //Һ����/д����
sbit LCD_EN = P3 ^ 7; //Һ��ʹ�ܿ���
sbit LCD_PSB = P3 ^ 2; //��/����ʽ����
sbit FM = P2 ^ 4;//���������ƿ�
sbit RS = P2 ^ 5;
sbit T_CLK = P2 ^ 0; //ʵʱʱ��ʱ�������� //
sbit T_IO = P2 ^ 1; //ʵʱʱ������������ //
sbit T_RST = P2 ^ 2; //ʵʱʱ�Ӹ�λ������ //
sbit ds = P2 ^ 3;
sbit EN = P2 ^ 6;
sbit ZZ = P2 ^ 7;
sbit FZ = P3 ^ 1;
sbit ACC0 = ACC ^ 0;
sbit ACC7 = ACC ^ 7;
uint temp1, s_temp; //�������α���
float f_temp; //���帡���ͱ���
uchar num, num1, flag, count, a, b;
uchar unlock_i;//���ܱ�־λ
uchar t[4];
uchar t1[4];
void delay_ms(uint z)//����ʱ
{
	uint x, y;
	for (x = z; x > 0; x--)
	for (y = 110; y > 0; y--);
}
void delay() //����ʱ����Լ5us
{
	;;
}
void reshi()
{
	if (RS == 1)
	{
		unlock_i = 1;
	}
	else
	{
		unlock_i = 0;
	}
}
uchar code mima[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '*' };
void lcd_xieping0(uchar x, uchar y, uchar date);
void lcd_xieping(uchar x, uchar y, uchar *str);
//********************************************************
// ������ʾ
//********************************************************
void kjxs()
{
	uint i, j;
	lcd_xieping(0, 0, "PLEASE SET CODE");

	delay_ms(4000);

	for (j = 3; j > 0; j--)
	{
		for (i = 0; i < 8; i++)
		{
			lcd_xieping(3, i, "*");
			delay_ms(250);
		}
		lcd_xieping(3, 0, " ");
	}
}
//********************************************************
// 12864��ʾ
//********************************************************
void write_cmd(uchar cmd)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_EN = 0;
	P0 = cmd;
	delay_ms(5);
	LCD_EN = 1;
	delay_ms(5);
	LCD_EN = 0;
}
void write_dat(uchar dat)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_EN = 0;
	P0 = dat;
	delay_ms(5);
	LCD_EN = 1;
	delay_ms(5);
	LCD_EN = 0;
}
void lcd_xieping0(uchar x, uchar y, uchar date)
{
	switch (x)
	{
	case 0: write_cmd(0x80 + y); break;
	case 1: write_cmd(0x90 + y); break;
	case 2: write_cmd(0x88 + y); break;
	case 3: write_cmd(0x98 + y); break;
	}
	write_dat(date);
}
void lcd_xieping(uchar x, uchar y, uchar *str)
{
	switch (x)
	{
	case 0: write_cmd(0x80 + y); break;
	case 1: write_cmd(0x90 + y); break;
	case 2: write_cmd(0x88 + y); break;
	case 3: write_cmd(0x98 + y); break;
	}
	while (*str)
	{
		write_dat(*str);
		str++;
	}
}
void lcd_init()
{
	LCD_PSB = 1; //���ڷ�ʽ
	write_cmd(0x30); //����ָ�����
	delay_ms(5);
	write_cmd(0x0C); //��ʾ�����ع��
	delay_ms(5);
	write_cmd(0x01); //���LCD����ʾ����
	delay_ms(5);
}
//**************************************************************
// ����ɨ�躯��
//**************************************************************
uchar keyscan1() //�������ɨ�躯��
{
	uchar temp;
	while (!num)
	{
		P1 = 0xfe; //��ֵ
		temp = P1; //��������
		temp = temp & 0xf0; //������
		if (temp != 0xf0) //�ж�
		{
			delay_ms(2); //��ʱ����
			temp = P1; //��������
			temp = temp & 0xf0;
			if (temp != 0xf0)
			{
				switch (temp) //���֧ѡ��
				{
				case 0x70:num = 1; break; //����
				case 0xb0:num = 2; break;
				case 0xd0:num = 3; break;
				case 0xe0:num = 4; break;
				}
				while (temp != 0xf0)
				{
					temp = P1;
					temp = temp & 0xf0;
				}//�ȴ������ͷ�
			}
		}
		P1 = 0xfd; //��ֵ
		temp = P1; //��������
		temp = temp & 0xf0; //������
		if (temp != 0xf0) //�ж�
		{
			delay_ms(2); //��ʱ����
			temp = P1; //��������
			temp = temp & 0xf0;
			if (temp != 0xf0)
			{
				switch (temp) //���֧ѡ��
				{
				case 0x70:num = 5; break; //����
				case 0xb0:num = 6; break;
				case 0xd0:num = 7; break;
				case 0xe0:num = 8; break;
				}
				while (temp != 0xf0)
				{
					temp = P1;
					temp = temp & 0xf0;
				}//�ȴ������ͷ�
			}
		}
		P1 = 0xfb; //��ֵ
		temp = P1; //��������
		temp = temp & 0xf0; //������
		if (temp != 0xf0) //�ж�
		{
			delay_ms(2); //��ʱ����
			temp = P1; //��������
			temp = temp & 0xf0;
			if (temp != 0xf0)
			{
				switch (temp) //���֧ѡ��
				{
				case 0x70:num = 9; break; //����
				case 0xb0:num = 10; break;
				case 0xd0:num = 11; break;
				case 0xe0:num = 12; break;
				}
				while (temp != 0xf0)
				{
					temp = P1;
					temp = temp & 0xf0;
				}//�ȴ������ͷ�
			}
		}
	}
	return(num); //����ֵ
}
uchar keyscan2()
{
	uchar temp;
	while (!num1)
	{
		P1 = 0xf7; //��ֵ
		temp = P1; //��������
		temp = temp & 0xf0; //������
		if (temp != 0xf0) //�ж�
		{
			delay_ms(2); //��ʱ����
			temp = P1; //��������
			temp = temp & 0xf0;
			if (temp != 0xf0)
			{
				switch (temp) //���֧ѡ��
				{
				case 0x70:num1 = 1; break; //����
				case 0xb0:num1 = 2; break;
				case 0xd0:num1 = 3; break;
				case 0xe0:num1 = 4; break;
				}
				while (temp != 0xf0)
				{
					temp = P1;
					temp = temp & 0xf0;
				}//�ȴ������ͷ�
			}
		}
	}
	return(num1);
}

//**************************************************************
// EPPROM
//**************************************************************
void start() //�����ź�
{
	SDA = 1;
	delay();
	SCL = 1;
	delay();
	SDA = 0;
	delay();
}
void stop() //ֹͣ�ź�
{
	SDA = 0;
	delay();
	SCL = 1;
	delay();
	SDA = 1;
	delay();
}
void respons() //��Ӧ�ź�
{
	uchar i;
	SCL = 1;
	delay();
	while ((SDA == 1) && (i < 250))
		i++;
	SCL = 0;
	delay();
}
void writebyte(uchar date) //дһ���ֽ�
{
	uchar i, temp;
	temp = date;
	for (i = 0; i < 8; i++)
	{
		temp = temp << 1;
		SCL = 0;
		delay();
		SDA = CY;
		delay();
		SCL = 1;
		delay();
	}
	SCL = 0;
	delay();
	SDA = 1; //�ͷ�����
	delay();
}
uchar readbyte() //��һ���ֽ�
{
	uchar i, k;
	SCL = 0;
	delay();
	SDA = 1;
	for (i = 0; i < 8; i++)
	{
		SCL = 1;
		delay();
		k = (k << 1) | SDA;
		SCL = 0;
		delay();
	}
	delay();
	return(k);
}
void write(uchar add, uchar date) //��һ����ַдһ���ֽ�
{
	start();
	writebyte(0xa0);
	respons();
	writebyte(add);
	respons();
	writebyte(date);
	respons();
	stop();
}
uchar read(uchar add) //��һ����ַ��һ���ֽ�
{
	start();
	writebyte(0xa0);
	respons();
	writebyte(add);
	respons();
	start();
	writebyte(0xa1);
	respons();
	b = readbyte();
	respons();
	stop();
	return(b);
}



//**************************************************************
// ���ܺ���
//**************************************************************
void unlock()
{
	uchar in, i;
	if (num == 0)
	{
		lcd_xieping(3, 0, " ");
		for (i = 0; i < 4; i++)
		{
			t1[i] = keyscan1();
			lcd_xieping(3, i, "*");
			num = 0;
		}//������
	}
	in = keyscan1();
	if (in == 12)//in-ȷ������־λ
	{
		in = 0;
		num = 0;
		if ((t1[0] == t[0]) && (t1[1] == t[1]) && (t1[2] == t[2]) && (t1[3] == t[3]))
		{
			flag = 1;//���ܳɹ�����־λ
			//unlock_i=1;
			a = 0;//���ܼ���־
			lcd_xieping(0, 0, "PLEASE SET CODE ");
			lcd_xieping(2, 0, " INPUT PASSWORD ");

			delay_ms(1500);
			lcd_xieping(1, 0, "PLEASE COME IN");

		}
		else
		{
			flag = 0;
			count++;
			if (count == 3)
			{
				count = 0;
				num = 1;
				lcd_xieping(1, 0, "��������������������");

				FM = 0;
				delay_ms(1000);
				FM = 1;
			}
		}
	}
}

  }
  ib = keyscan1();
  if (ib == 12)
  {
	  ib = 0;
	  num = 0;
	  if (t2[0] == t3[0] && t2[1] == t3[1] && t2[2] == t3[2] && t2[3] == t3[3])
	  {
		  t[0] = t3[0];
		  t[1] = t3[1];
		  t[2] = t3[2];
		  t[3] = t3[3];
		  lcd_xieping(3, 0, " �����޸ĳɹ� ");
		  flag = 0;
		  for (j = 0; j < 4; j++)
		  {
			  l = j + 1;
			  write(l, t[j]);
			  delay_ms(10);
		  }//24C08д����
		  delay_ms(1000);
	  }
	  else
	  {
		  lcd_xieping(2, 0, "INPUT PASSWORD");
		  flag = 1;
		  delay_ms(500);
	  }
  }
  }
  //**************************************************************
  // ��ʾ����
  //**************************************************************
  void xianshi()
  {

	  s_temp = f_temp * 100;
	  temp0[7] = (s_temp / 1000) + 48;
	  temp0[8] = (s_temp % 1000 / 100) + 48;
	  temp0[10] = (s_temp % 100 / 10) + 48;
	  temp0[11] = (s_temp % 10) + 48;
	  num = 0;
  }

  //**************************************************************
  // ������
  //**************************************************************
  void main()
  {
	  uchar m;
	  unlock_i = 1;
	  lcd_init(); //Һ����ʼ��
	  //Init1302();
	  kjxs(); //������ʾ
	  for (m = 0; m < 4; m++)
	  {
		  t[m] = read(m + 1);
		  delay_ms(10);
	  }//24C08������
	  while (1)
	  {
		  reshi();
		  if (!unlock_i)
		  {
			  unlock();//���ܺ���
		  }

		  if (flag == 1)
		  {
			  num1 = 0;
			  a = keyscan2();

			  if (a == 2)
			  {
				  xiugaimima();//�޸����뺯��
			  }
		  }
	  }
  }