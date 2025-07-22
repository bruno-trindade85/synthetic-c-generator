import os
import random

# Diretório de saída
output_dir = "synthetic_c_dataset"
os.makedirs(output_dir, exist_ok=True)

# Número de exemplos
num_samples = 20

# Gera código C com ou sem vazamento
def gerar_codigo_c(index, com_vazamento):
    nome_arquivo = f"sample_{index:02d}_{'leak' if com_vazamento else 'no_leak'}.c"
    caminho = os.path.join(output_dir, nome_arquivo)

    codigo = '#include <stdlib.h>\n#include <stdio.h>\n\n'
    codigo += 'void exemplo() {\n'
    codigo += '    char *buffer = (char *)malloc(100);\n'
    codigo += '    if (buffer == NULL) return;\n'
    codigo += '    printf("Usando o buffer...\\n");\n'
    
    # Inserir vazamento ou não
    if not com_vazamento:
        codigo += '    free(buffer);\n'
    codigo += '}\n\nint main() {\n    exemplo();\n    return 0;\n}'

    with open(caminho, "w") as f:
        f.write(codigo)

    return nome_arquivo, "leak" if com_vazamento else "no_leak"

# Gera os arquivos e grava labels
labels = []
for i in range(1, num_samples + 1):
    com_vazamento = random.choice([True, False])
    nome_arquivo, label = gerar_codigo_c(i, com_vazamento)
    labels.append((nome_arquivo, label))

# Salvar labels em CSV
with open(os.path.join(output_dir, "labels.csv"), "w") as f:
    f.write("arquivo,label\n")
    for nome, label in labels:
        f.write(f"{nome},{label}\n")
