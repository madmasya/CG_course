#include<conio.h>
#include<stdio.h>
#include<D:\Downloads\��\����������\������������ �������\labs\libwinbgi\src\graphics.h>
#include<math.h>
float v11, v12, v13, v21, v22, v23, v32, v33, v43; //������������, ����������� �� ������� (9.9)
float screen_dist, c1, c2;
perspective(float x, float y, float z, float* pX, float* pY)
{
	float xe, ye, ze;
	xe = v11 * x + v21 * y;
	ye = v12 * x + v22 * y + v32 * z;
	ze = v13 * x + v23 * y + v33 * z + v43;
	/* �������� ����������, ����������� �� (9.12)*/
	*pX = screen_dist * xe / ze + c1;
	*pY = screen_dist * ye / ze + c2;
	return 0;
}
coeff(float rho, float theta, float phi)
{
	float th, ph, costh, sinth, cosph, sinph, factor;
	factor = atan(1.0) / 45.0;
	/*���� � ��������*/
	th = theta * factor; ph = phi * factor;
	costh = cos(th); sinth = sin(th);
	cosph = cos(ph); sinph = sin(ph);
	/*�������� ������� V ��.(9.9) */
	v11 = -sinth; v12 = -cosph * costh; v13 = -sinph * costh;
	v21 = costh; v22 = -cosph * sinth; v23 = -sinph * sinth;
	v32 = sinph; v33 = -cosph; v43 = rho;
	return 0;
}
mv(float x, float y, float z)
{
	float X, Y;
	perspective(x, y, z, &X, &Y);
	moveto(X, Y);
	return 0;
}
dw(float x, float y, float z)
{
	float X, Y;
	perspective(x, y, z, &X, &Y);
	lineto(X, Y);
	return 0;
}
main()
{
	float rho, theta, phi, h = 10.0;
	printf("���������� �� ����������� rho = EO:");
	scanf(" % f", &rho);
	printf("\n������� ��� ���� � ��������.\n");
	printf("\n���� theta ���������� �� ����������� �� ��� � : ");
	scanf(" % f", &theta);
	printf("���� phi ���������� �� ��������� �� ��� z : ");
	scanf(" % f", &phi);
	printf("���������� �� ����� ���������� �� ������ (��������, �.) :");
	scanf(" % f", &screen_dist);
	printf("����������� c1 = ");
	scanf(" % f", &c1);
	printf("����������� �2 = ");
	scanf(" % f", &c2);
	coeff(rho, theta, phi);
	initwindow(1920/2, 1080/2, "test");
	mv(h, -h, -h); dw(h, h, -h); dw(-h, h, -h); dw(-h, h, h); dw(-h, -h, h); dw(h, -h, h);
	dw(h, -h, -h);
	mv(h, h, -h); dw(h, h, h); dw(-h, h, h);
	mv(h, h, h); dw(h, -h, h);
	mv(h, -h, -h); dw(-h, -h, -h); dw(-h, h, -h);
	mv(-h, -h, -h); dw(-h, -h, h);
	return 0;
}