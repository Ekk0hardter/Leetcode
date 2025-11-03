from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import sys

def text_similarity():
    # 读取输入的文本列表，输入格式为类似 ["text1", "text2", "text3"] 的形式
    input_text = sys.stdin.readline().strip()
    # 去除前后的方括号，按逗号分割并去除引号和空格，得到文本列表
    texts = [s.strip().strip('"') for s in input_text.strip('[]').split(',')]
    
    vectorizer = TfidfVectorizer()
    tfidf_matrix = vectorizer.fit_transform(texts)
    similarity_matrix = cosine_similarity(tfidf_matrix)
    
    result = []
    for row in similarity_matrix:
        result_row = [f"{val:.2f}" for val in row]
        result.append(result_row)
    
    # 输出结果，格式为二维列表的字符串形式
    print(result)

if __name__ == "__main__":
    text_similarity()