#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	// �� RGB ��Ҹ� �����ϴµ� ����� Ÿ��
	// ����μ��� 0~255�� ������ ���´�
	typedef unsigned char element_t;

	// 32��Ʈ ������ Ÿ��
	typedef unsigned long color32_t;

	// ó�� ���� �� ���� �Ǵ� �⺻��(���� ���)
	enum { defR = 255, defG = 255, defB = 255 };

public:
	// ������
	Color();
	Color(element_t R, element_t G, element_t B);

	// ������
	void SetR(element_t val);
	void SetG(element_t val);
	void SetB(element_t val);
	element_t GetR() const;
	element_t GetG() const;
	element_t GetB() const;

	// RGB�� ���� 32��Ʈ ������ ���� ��ȯ/����
	// 32��Ʈ �߿��� 24��Ʈ�� ����Ѵ�
	// �� RGB �� ��Һ��� 8��Ʈ�� ����
	void SetColor32(color32_t val);
	color32_t GetColor32() const;

	// ��ü ��⸦ ��ȭ��Ų��
	void AdjustBright(int delta);

	// ���� ����Ѵ�
	// endLine == true�̸� ���͵� ����ش�
	void Print(bool endLine = true) const;

protected:
	// ������ ��� ���� 0~255 ���� ������ ������ش�
	// �ҽ� �ڵ��� �ߺ��� ���� ���ؼ� ����� �� �ִ�
	int PutInRange(int val);

protected:
	// ������ RGB�� �����Ѵ�
	unsigned char R;
	unsigned char G;
	unsigned char B;

public:
	// ���� ���̴� ������ ���� ����� ������ش�
	static const Color Black;
	static const Color White;
	static const Color Green;
	static const Color Blue;
	static const Color Red;
	static const Color Yellow;
	static const Color Violet;
	static const Color Gray;
};

#endif // !COLOR_H

