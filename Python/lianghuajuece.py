# ���뺯����

#����ز�ǰҪ��������
def initialize(context):
    set_params()        #1���ò߲���
    set_variables() #2�����м����
    set_backtest()   #3���ûز�����


#1
#���ò߲���
def set_params():
    g.tc=15  # ����Ƶ��
    g.yb=63  # ��������
    g.N=20   # �ֲ���Ŀ
    g.factors=["market_cap","roe"] # �û�ѡ����������
    # ���ӵ�Ȩ����1��ʾ����ֵԽСԽ�ã�-1��ʾ����ֵԽ��Խ��
    g.weights=[[1],[-1]]
    
    
#2
#�����м����
def set_variables():
    g.t=0              #��¼�ز����е�����
    g.if_trade=False   #�����Ƿ���
    
    
#3
#���ûز�����
def set_backtest():
    set_option('use_real_price', True)#����ʵ�۸���
    log.set_level('order', 'error')
