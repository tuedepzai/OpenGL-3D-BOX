#pragma once


namespace conf {
	int WIDTH = 800, HEIGHT = 800;
	GLfloat BG_R = 106, BG_G = 107, BG_B = 131, BG_A = 1;

    float vertices[] = {
        // Position        // Color            // Texture Coordinates
        // Front face
        0.0f, 0.0f,  0.0f, .45f, .35f, .25f, 0.0f, 0.0f, // 0 - Bottom Left Front
        0.0f, 0.5f,  0.0f, .85f, .95f, .75f, 0.0f, 1.0f, // 1 - Top Left Front
        0.5f, 0.5f,  0.0f, .85f, .95f, .15f, 1.0f, 1.0f, // 2 - Top Right Front
        0.5f, 0.0f,  0.0f, .25f, .35f, .45f, 1.0f, 0.0f, // 3 - Bottom Right Front

        // Back face
        0.0f, 0.0f, -0.5f, .25f, .35f, .45f, 0.0f, 0.0f, // 4 - Bottom Left Back
        0.0f, 0.5f, -0.5f, .25f, .35f, .45f, 0.0f, 1.0f, // 5 - Top Left Back
        0.5f, 0.5f, -0.5f, .25f, .35f, .45f, 1.0f, 1.0f, // 6 - Top Right Back
        0.5f, 0.0f, -0.5f, .25f, .35f, .45f, 1.0f, 0.0f, // 7 - Bottom Right Back

        // Left face
        0.0f, 0.0f, -0.5f, .25f, .35f, .45f, 1.0f, 0.0f, // 8 - Bottom Left Back
        0.0f, 0.0f,  0.0f, .25f, .35f, .45f, 0.0f, 0.0f, // 9 - Bottom Left Front
        0.0f, 0.5f,  0.0f, .25f, .35f, .45f, 0.0f, 1.0f, // 10 - Top Left Front
        0.0f, 0.5f, -0.5f, .25f, .35f, .45f, 1.0f, 1.0f, // 11 - Top Left Back

        // Right face
        0.5f, 0.0f,  0.0f, .25f, .35f, .45f, 0.0f, 0.0f, // 12 - Bottom Right Front
        0.5f, 0.0f, -0.5f, .25f, .35f, .45f, 1.0f, 0.0f, // 13 - Bottom Right Back
        0.5f, 0.5f, -0.5f, .25f, .35f, .45f, 1.0f, 1.0f, // 14 - Top Right Back
        0.5f, 0.5f,  0.0f, .25f, .35f, .45f, 0.0f, 1.0f, // 15 - Top Right Front

        // Top face
        0.0f, 0.5f,  0.0f, .25f, .35f, .45f, 0.0f, 0.0f, // 16 - Top Left Front
        0.5f, 0.5f,  0.0f, .25f, .35f, .45f, 1.0f, 0.0f, // 17 - Top Right Front
        0.5f, 0.5f, -0.5f, .25f, .35f, .45f, 1.0f, 1.0f, // 18 - Top Right Back
        0.0f, 0.5f, -0.5f, .25f, .35f, .45f, 0.0f, 1.0f, // 19 - Top Left Back

        // Bottom face
        0.0f, 0.0f,  0.0f, .25f, .35f, .45f, 0.0f, 0.0f, // 20 - Bottom Left Front
        0.5f, 0.0f,  0.0f, .25f, .35f, .45f, 1.0f, 0.0f, // 21 - Bottom Right Front
        0.5f, 0.0f, -0.5f, .25f, .35f, .45f, 1.0f, 1.0f, // 22 - Bottom Right Back
        0.0f, 0.0f, -0.5f, .25f, .35f, .45f, 0.0f, 1.0f  // 23 - Bottom Left Back
    };
    int indicies[] = {
        // Front face
        0, 1, 2,
        0, 2, 3,

        // Back face
        4, 5, 6,
        4, 6, 7,

        // Left face
        8, 9, 10,
        8, 10, 11,

        // Right face
        12, 13, 14,
        12, 14, 15,

        // Top face
        16, 17, 18,
        16, 18, 19,

        // Bottom face
        20, 21, 22,
        20, 22, 23
    };


}